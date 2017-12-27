#include <gtest.h>
#include <OpenGL/gl.h>
#include <GLUT/glut.h>

#define TEST_NAME (testing::UnitTest::GetInstance()->current_test_info()->name())
#define CHAPTER04 chapter04_opengl_example
#define CHAPTER05 chapter05_opengl_foundation_tool

using namespace testing;

/**
 * 사각형 그리기
 */
TEST(CHAPTER04, code4_8)
{
    glutCreateWindow(TEST_NAME);
    glutDisplayFunc([]()
                    {
                        glClear(GL_COLOR_BUFFER_BIT);
                        glBegin(GL_POLYGON);

                        glVertex3f(-0.5, -0.5, 0.0);
                        glVertex3f(0.5, -0.5, 0.0);
                        glVertex3f(0.5, 0.5, 0.0);
                        glVertex3f(-0.5, 0.5, 0.0);

                        glEnd();
                        glFlush();
                    });
    glutMainLoop();
}

/**
 * 뷰포트에 사각형 그리기
 */
TEST(CHAPTER05, code5_4)
{
    glutInitDisplayMode(GLUT_RGB); // 윈도우의 기본컬러 모드를 RGB로 설정
    glutInitWindowSize(300, 300);
    glutInitWindowPosition(0, 0);
    glutCreateWindow(TEST_NAME);
    glClearColor(0, 0, 0, 1);
    glMatrixMode(GL_PROJECTION); // 투상 행렬을 변환대상으로 설정하라는 명령
    glLoadIdentity(); // 이 행렬을 일단 항등 행렬로 실으라는 명령
//    glOrtho(-1, 1, -1, 1, -1, 1);
//    glOrtho(-0.5, 1.5, -0.5, 1.5, -1, 1);
    glOrtho(-2, 2, -1, 1, -1, 1);
    glutDisplayFunc([]()
                    {
                        glClear(GL_COLOR_BUFFER_BIT); // 프레임 버퍼를 초기화,
                        glViewport(0, 0, 300, 300); // view port 설정
                        glColor3f(1, 1, 1);
                        glBegin(GL_POLYGON);

                        glVertex3f(-0.5, -0.5, 0.0);
                        glVertex3f(0.5, -0.5, 0.0);
                        glVertex3f(0.5, 0.5, 0.0);
                        glVertex3f(-0.5, 0.5, 0.0);

                        glEnd();
                        glFlush();
                    });
    glutMainLoop();
}

/**
 * 투상면과 뷰포트의 종횡비를 일치시켜 왜곡을 없앰
 *
 * glOrtho
 * 가시부피(View Volume)의 개념을 이해하자
 *
 * 리쉐이드 콜백
 * 리쉐이드 콜백이란
 * 1. 처음 윈도우가 호출될 때, 윈도우 위치가 변경될 때, 윈도우 사이즈가 변경될 때 호출된다.
 * 투상면과 뷰포트의 종횡비가 일치하면, 리쉐이프가 일어나도 왜곡이 일어나지 않는다.
 */
TEST(CHAPTER05, code5_5)
{
    glutInitDisplayMode(GLUT_RGB);
    glutInitWindowSize(300, 300);
    glutInitWindowPosition(0, 0);
    glutCreateWindow(TEST_NAME);
    glClearColor(1, 1, 1, 1);
    glutDisplayFunc([]()
                    {
                        glClear(GL_COLOR_BUFFER_BIT); // 프레임 버퍼를 초기화,
                        glColor3f(0.5, 0.5, 0.5);
                        glBegin(GL_POLYGON);

                        glVertex3f(-0.5, -0.5, 0.0);
                        glVertex3f(0.5, -0.5, 0.0);
                        glVertex3f(0.5, 0.5, 0.0);
                        glVertex3f(-0.5, 0.5, 0.0);

                        glEnd();
                        glFlush();
                    });
    glutReshapeFunc([](int newWidth, int newHeight)
                    {
                        glViewport(0, 0, newWidth, newHeight);
                        GLfloat widthFactor = (GLfloat) newWidth / (GLfloat) 300; // 폭의 증가율
                        GLfloat heightFactor = (GLfloat) newHeight / (GLfloat) 300; // 높이의 증가율
                        glMatrixMode(GL_PROJECTION);
                        glLoadIdentity();
                        // 투상면과 뷰포트의 종횡비 일치, 가시부피를 설정, 장면을 포착하는 틀
                        glOrtho(-1 * widthFactor, 1 * widthFactor, -1 * heightFactor, 1 * heightFactor, -1, 1);
                    });
    glutMainLoop();
}

/**
 * 키보드 콜백
 */
TEST(CHAPTER05, code5_6)
{
    glutInitDisplayMode(GLUT_RGB);
    glutInitWindowSize(300, 300);
    glutInitWindowPosition(0, 0);
    glutCreateWindow(TEST_NAME);
    glutDisplayFunc([]()
                    {
                    });
    glutKeyboardFunc([](unsigned char key, int x, int y)
                     {
                         if (key == 'a')
                             printf("hello!\n");
                     });
    glutMainLoop();
}

int topLeftX = 0, topLeftY = 0, bottonRightX = 0, bottonRightY = 0;

/**
 * 마우스 콜백
 */
TEST(CHAPTER05, code5_7)
{
    glutInitDisplayMode(GLUT_RGB);
    glutInitWindowSize(300, 300);
    glutInitWindowPosition(0, 0);
    glutCreateWindow(TEST_NAME);
    glClearColor(1, 1, 1, 1);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0, 1, 0, 1, -1, 1);

    // 버튼을 누르거나 마우스를 움직일 때 이벤트 콜백
    glutMouseFunc([](GLint button, GLint state, GLint x, GLint y)
                  {
                      if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
                      {
                          topLeftX = x;
                          topLeftY = y;
                      }
                  });
    // 마우스를 누른 상태에서 움직이는 이벤트 콜백
    glutMotionFunc([](GLint x, GLint y)
                   {
                       bottonRightX = x;
                       bottonRightY = y;
                       glutPostRedisplay();
                   });
    // draw
    glutDisplayFunc([]()
                    {
                        glViewport(0, 0, 300, 300);
                        glClear(GL_COLOR_BUFFER_BIT);
                        glColor3f(0.5, 0.5, 0.5);
                        glBegin(GL_POLYGON);

                        glVertex3f(topLeftX / 300.0, (300 - topLeftY) / 300.0, 0);
                        glVertex3f(topLeftX / 300.0, (300 - bottonRightY) / 300.0, 0);
                        glVertex3f(bottonRightX / 300.0, (300 - bottonRightY) / 300.0, 0.0);
                        glVertex3f(bottonRightX / 300.0, (300 - topLeftY) / 300.0, 0.0);

                        glEnd();
                        glFlush();
                    });
    glutMainLoop();
}

#undef index;

#define PALETTE_COUNT 16
uint8_t palette[PALETTE_COUNT][3] = {{255, 255, 255},      // WHITE
                                     {0,   255, 255},      // CYAN
                                     {255, 0,   255},      // PURPLE
                                     {0,   0,   255},      // BLUE
                                     {192, 192, 192},      // LIGHT GRAY
                                     {128, 128, 128},      // DARK GRAY
                                     {0,   128, 128},      // DARK TEAL
                                     {128, 0,   128},      // DARK PURPLE
                                     {0,   0,   128},      // DARK BLUE
                                     {255, 255, 0},      // YELLOW
                                     {0,   255, 0},      // GREEN
                                     {128, 128, 0},      // DARK YELLOW
                                     {0,   128, 0},      // DARK GREEN
                                     {255, 0,   0},      // RED
                                     {128, 0,   0},      // DARK RED
                                     {0,   0,   0},      // BLACK
};
GLfloat delta = 0;
GLint palette_index = 0;
GLfloat red = 0, green = 0, blue = 0;

void timerHandler(int value)
{
    if (delta < 2)
    {
        delta += 0.01;
    }
    else
    {
        delta = 0;
        if (++palette_index >= PALETTE_COUNT)
        {
            palette_index = 0;
            glClear(GL_COLOR_BUFFER_BIT);
        }
    }
    glutPostRedisplay();
    glutTimerFunc(10, timerHandler, 1);
}

/**
 * 타이머 콜백 - 애니메이션
 */
TEST(CHAPTER05, code5_12)
{
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(0, 0);
    glutCreateWindow(TEST_NAME);
    glClearColor(0, 0, 0, 1);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-1, 1, -1, 1, -1, 1);

    glutTimerFunc(10, timerHandler, 1);
    glutDisplayFunc([]()
                    {
                        red = palette[palette_index][0] / 255.0;
                        green = palette[palette_index][1] / 255.0;
                        blue = palette[palette_index][2] / 255.0;

                        glColor3f(red, green, blue);
                        glBegin(GL_LINES);
                        glVertex3f(-1 + delta, 1, 0);
                        glVertex3f(1 - delta, -1, 0);
                        glVertex3f(-1, -1 + delta, 0);
                        glVertex3f(1, 1 - delta, 0);

                        glEnd();
                        glutSwapBuffers(); // 묵시적으로 glFlush()가 실행되어 전 코드들이 버퍼에 기록됨 그리고 스
                    });
    glutMainLoop();
}

GLfloat colors[8][3] = {{.2, .2, .2},
                        {1,  0,  0},
                        {1,  1,  0},
                        {0,  1,  0},
                        {0,  0,  1},
                        {1,  0,  1},
                        {1,  1,  1},
                        {0,  1,  1}};
GLfloat vertexs[8][3] = {{-.25, -.25, .25},
                         {-.25, .25,  .25},
                         {.25,  .25,  .25},
                         {.25,  -.25, .25},
                         {-.25, -.25, -.25},
                         {-.25, .25,  -.25},
                         {.25,  .25,  -.25},
                         {.25,  -.25, -.25}};
GLubyte vertexList[24] = {0, 3, 2, 1, 2, 3, 7, 6, 0, 4, 7, 3, 1, 2, 6, 5, 4, 5, 6, 7, 0, 1, 5, 4};

/**
 * 8개의 정점과 6개의 면으로 정육면체 그리기
 */
TEST(CHAPTER05, code5_13)
{
    glutInitDisplayMode(GLUT_RGB);
    glutInitWindowSize(300, 300);
    glutInitWindowPosition(0, 0);
    glutCreateWindow(TEST_NAME);
    glClearColor(1, 1, 1, 1);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-1, 1, -1, 1, -1, 1);
    glutDisplayFunc([]()
                    {
                        glClear(GL_COLOR_BUFFER_BIT);
                        glFrontFace(GL_CCW); // 포면을 반시계 방향 순서로 기술하겠다는 의미 counter clockwise
                        glEnable(GL_CULL_FACE); // ?
                        glEnableClientState(GL_COLOR_ARRAY); // 정점 배열 활성화
                        glEnableClientState(GL_VERTEX_ARRAY);
                        glColorPointer(3, GL_FLOAT, 0, colors); // 정점 색 저장
                        glVertexPointer(3, GL_FLOAT, 0, vertexs); // 정점 좌표 저장
                        glMatrixMode(GL_MODELVIEW);
                        glLoadIdentity();
                        glRotatef(30, 1, 1, 1);
                        for (GLint i = 0; i < 6; i++)
                            glDrawElements(GL_POLYGON, 4, GL_UNSIGNED_BYTE, &vertexList[4 * i]);
                        glFlush();
                    });
    glutMainLoop();
}

int listID;

/**
 * 보류 모드
 */
TEST(CHAPTER05, code5_14)
{
    glutInitDisplayMode(GLUT_RGB);
    glutInitWindowSize(300, 300);
    glutInitWindowPosition(0, 0);
    glutCreateWindow(TEST_NAME);
    glClearColor(1, 1, 1, 1);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-1, 1, -1, 1, -1, 1);
    glutDisplayFunc([]()
                    {
                        glClear(GL_COLOR_BUFFER_BIT);
                        glViewport(0, 0, 300, 300);
                        glCallList(listID); // 리스트 실행
                        glFlush();
                    });
    // list 설정
    listID = glGenLists(1); // 사용 안된 일련의 값을 반환
    glNewList(listID, GL_COMPILE); // 리스트 아이템 정의, 실행하지 않고 COMPILE된 버전으로 만든다.
    glBegin(GL_POLYGON);
    glColor3f(0.5, 0.5, 0.5);
    glVertex3f(-0.5, -0.5, 0.0);
    glVertex3f(0.5, -0.5, 0.0);
    glVertex3f(0.5, 0.5, 0.0);
    glVertex3f(-0.5, 0.5, 0.0);
    glEnd();
    glEndList();

    glutMainLoop();
}