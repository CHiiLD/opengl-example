#include <gtest.h>
#include <OpenGL/gl.h>
#include <GLUT/glut.h>
#include <math.h>

#define TEST_NAME (testing::UnitTest::GetInstance()->current_test_info()->name())
#define CHAPTER06 chapter06_coordinate
#define CHAPTER07 chapter07_projection_viewport_transformation
#define CHAPTER08 chapter08_visibility_estimation
#define CHAPTER09 chapter09_raster_transformation

using namespace testing;

/**
 * 기하 변환, 물체 변환과 좌표계 변환의 차이 알기
 */
TEST(CHAPTER06, code6_3)
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
                        glColor3f(1, 0, 0);
                        glMatrixMode(GL_MODELVIEW);
                        glLoadIdentity();
                        glRotatef(45, 0, 0, 1);
                        glTranslatef(0.6, 0, 0);
                        glutSolidCube(0.3);
                        glFlush();
                    });
    glutMainLoop();
}

void initRight()
{
    GLfloat mat_diffuse[] = {0.5, 0.4, 0.3, 1.0};
    GLfloat mat_specular[] = {1.0, 1.0, 1.0, 1.0};
    GLfloat mat_ambient[] = {0.5, 0.4, 0.3, 1.0};
    GLfloat mat_shininess[] = {15.0};
    GLfloat light_specular[] = {1.0, 1.0, 1.0, 1.0};
    GLfloat light_diffuse[] = {0.8, 0.8, 0.8, 1.0};
    GLfloat light_ambient[] = {0.3, 0.3, 0.3, 1.0};
    GLfloat light_position[] = {-3, 6, 3.0, 0.0};

    glShadeModel(GL_SMOOTH);
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    glLightfv(GL_LIGHT0, GL_POSITION, light_position);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, light_diffuse);
    glLightfv(GL_LIGHT0, GL_SPECULAR, light_specular);
    glLightfv(GL_LIGHT0, GL_AMBIENT, light_ambient);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);
    glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
    glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient);
    glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess);
}

/**
 * 시점 변환
 */
TEST(CHAPTER06, code6_8)
{
    glutInitDisplayMode(GLUT_RGBA | GLUT_SINGLE | GLUT_DEPTH);
    glutInitWindowSize(400, 400);
    glutInitWindowPosition(0, 0);
    glutCreateWindow(TEST_NAME);
    glClearColor(0.4, 0.4, 0.4, 0);

    initRight();

    glutDisplayFunc([]()
                    {
                        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
                        glMatrixMode(GL_MODELVIEW);
                        glLoadIdentity();

                        // 정면을 본 좌표, 0이 아닌 매개변수 중 하나라도 0이 들어가면 포트를 볼 수 없다.
                        gluLookAt(0, 0, 0, 0, 0, -1, 0, 1, 0);
//                        gluLookAt(0.3, 0.3, 0, 0, 0, -1, 0, 1, 0);
//                        gluLookAt(0, 0, 0, 0, 0, -1, 1, 1, 0);

                        glutSolidTeapot(0.5);
                        glFlush();
                    });

    glutReshapeFunc([](int w, int h)
                    {
                        glViewport(0, 0, w, h);
                        glMatrixMode(GL_PROJECTION);
                        glLoadIdentity();
                        glOrtho(-1, 1, -1, 1, -1, 1);
                    });

    glutMainLoop();
}

int width;
int height;

void drawScene()
{
    glColor3f(0.7, 0.7, 0.7);
    glPushMatrix();
    {
        glTranslatef(0.0, -1.0, 0.0);
        glBegin(GL_QUADS);
        glVertex3f(2.0, 0.0, 2.0);
        glVertex3f(2.0, 0.0, -2.0);
        glVertex3f(-2.0, 0.0, -2.0);
        glVertex3f(-2.0, 0.0, 2.0);
        glEnd();
    }
    glPopMatrix();

    glColor3f(0.3, 0.3, 0.7);
    glPushMatrix();
    {
        glTranslatef(0.0, 0.0, 0);
        glutWireTeapot(1);
    }
    glPopMatrix();
}

TEST(CHAPTER07, code7_2)
{
    width = 500;
    height = 500;
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA);
    glutInitWindowSize(width, height);
    glutInitWindowPosition(0, 0);
    glutCreateWindow(TEST_NAME);

    glClearColor(1.0, 1.0, 1.0, 1.0);
    glMatrixMode(GL_PROJECTION); // 행렬 모드를 투상 행렬로 설정
    glLoadIdentity();

    glOrtho(-2.0, 2.0, -2.0, 2.0, 0.5, 5.0); // 기본 투상 방법을 평행 투상으로
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity(); // 모델 뷰 행렬도 항등 행렬로 초기화

    glutDisplayFunc([]()
                    {
                        glClear(GL_COLOR_BUFFER_BIT);
                        glColor3f(1.0, 1.0, 1.0);
                        glViewport(0, 0, width / 2, height / 2);
                        glPushMatrix();
                        {
                            gluLookAt(0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
                            drawScene();
                        }
                        glPopMatrix();

                        glViewport(width / 2, 0, width / 2, height / 2);
                        glPushMatrix();
                        {
                            gluLookAt(1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
                            drawScene();
                        }
                        glPopMatrix();

                        glViewport(0, height / 2, width / 2, height / 2);
                        glPushMatrix();
                        {
                            gluLookAt(0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, -1.0);
                            drawScene();
                        }
                        glPopMatrix();

                        glViewport(width / 2, height / 2, width / 2, height / 2);
                        glMatrixMode(GL_PROJECTION);
                        glPushMatrix();
                        {
                            glLoadIdentity();
                            gluPerspective(30, 1.0, 3.0, 50.0);
                            glMatrixMode(GL_MODELVIEW);
                            glPushMatrix();
                            {
                                gluLookAt(4.0, 4.0, 4.0, 0.0, 0.0, 0.0, 0.0, 0, 0.0);
                                drawScene();
                            }
                            glPopMatrix();
                            glMatrixMode(GL_PROJECTION);
                        }
                        glPopMatrix();

                        glFlush();
                    });

    glutReshapeFunc([](int w, int h)
                    {
                        width = w;
                        height = h;
                    });

    glutMainLoop();
}

/**
 * 전면과 후면, 표면과 이면 이해하기 덤으로 은면도
 */
TEST(CHAPTER08, code8_3)
{
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA | GLUT_DEPTH);
    glutInitWindowSize(700, 700);
    glutInitWindowPosition(0, 0);
    glutCreateWindow(TEST_NAME);
    glClearColor(0.5, 0.5, 0.5, 0.0);

    // light
    GLfloat mat_diffuse[] = {0.5, 0.4, 0.3, 1.0};
    GLfloat mat_specular[] = {1.0, 1.0, 1.0, 1.0};
    GLfloat mat_ambient[] = {0.5, 0.4, 0.3, 1.0};
    GLfloat mat_shininess[] = {50.0};
    GLfloat light_specular[] = {1.0, 1.0, 1.0, 1.0};
    GLfloat light_diffuse[] = {0.8, 0.8, 0.8, 1.0};
    GLfloat light_ambient[] = {0.3, 0.3, 0.3, 1.0};
    GLfloat light_position[] = {-3, 2, 3.0, 0.0};
    glShadeModel(GL_SMOOTH);
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    glLightfv(GL_LIGHT0, GL_POSITION, light_position);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, light_diffuse);
    glLightfv(GL_LIGHT0, GL_SPECULAR, light_specular);
    glLightfv(GL_LIGHT0, GL_AMBIENT, light_ambient);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);
    glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
    glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient);
    glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess);

    // visibility
    glEnable(GL_CULL_FACE);
    glFrontFace(GL_CW); // 표면과 이면 바꾸기
    glPolygonMode(GL_FRONT, GL_FILL); // 표면은 채움으로 그리기
    glPolygonMode(GL_BACK, GL_LINE); // 이면은 선으로 그린다.
    glCullFace(GL_BACK); // 후면 제거
//    glCullFace(GL_FRONT); // 전면 제거
    glEnable(GL_DEPTH_TEST); // 은면 제거 하기

    glutDisplayFunc([]()
                    {
                        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
                        glMatrixMode(GL_MODELVIEW);
                        glLoadIdentity();
                        gluLookAt(0.0, 0.4, 0.5, 0.0, -0.5, -1.0, 0.0, 1.0, 0.0);
                        glutSolidTeapot(0.58);
//                        glutWireTeapot(0.58);
                        glFlush();
                    });
    glutReshapeFunc([](int w, int h)
                    {
                        glViewport(0, 0, (GLsizei) w, (GLsizei) h);
                        glMatrixMode(GL_PROJECTION);
                        glLoadIdentity();
                        glOrtho(-1.0, 1.0, -1.0, 1.0, -1.0, 2.0);
                    });
    glutMainLoop();
}

/**
 * 영상 합성
 */
TEST(CHAPTER08, code8_6)
{
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA | GLUT_DEPTH);
    glutInitWindowSize(400, 400);
    glutInitWindowPosition(0, 0);
    glutCreateWindow(TEST_NAME);
    glClearColor(1.0, 1.0, 1.0, 1.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-1.0, 1.0, -1.0, 1.0, 1.0, -1.0);
    glutDisplayFunc([]()
                    {
                        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
                        glEnable(GL_DEPTH_TEST);
                        glDepthMask(GL_FALSE);
                        {
                            glColor3f(0.62, 0.45, 0.35);
                            glBegin(GL_POLYGON);
                            glVertex3f(-.9, -.9, .1);
                            glVertex3f(.9, -.9, .1);
                            glVertex3f(.9, .9, .1);
                            glVertex3f(-.9, .9, .1);
                            glEnd();

                            glColor3f(.92, .63, .45);
                            glBegin(GL_TRIANGLES);
                            glVertex3f(-0.5, -0.5, 0.5);
                            glVertex3f(0.5, -0.5, 0.5);
                            glVertex3f(0.0, 0.5, 0.5);
                            glEnd();
                        }
                        glDepthMask(GL_TRUE);

                        glColorMask(GL_FALSE, GL_FALSE, GL_FALSE, GL_FALSE);
                        {
                            glColor3f(0.0, 1.0, 0.0);
                            glBegin(GL_POLYGON);
                            glVertex3f(-.9, -.9, .1);
                            glVertex3f(.9, -.9, .1);
                            glVertex3f(.9, .9, .1);
                            glVertex3f(-.9, .9, .1);
                            glEnd();
                        }
                        glColorMask(GL_TRUE, GL_TRUE, GL_TRUE, GL_TRUE);
                        glFlush();
                    });
    glutMainLoop();
}

/**
 * 점으로 원 그리기
 */
TEST(CHAPTER09, code9_10)
{
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA);
    glutInitWindowSize(300, 300);
    glutInitWindowPosition(0, 0);
    glutCreateWindow(TEST_NAME);
    glClearColor(1.0, 1.0, 1.0, 1.0);
    glutDisplayFunc([]()
                    {
                        const double PI = 3.1415;
                        GLfloat size[2];
                        glClear(GL_COLOR_BUFFER_BIT);
                        glGetFloatv(GL_POINT_SIZE_RANGE, size);
                        glPointSize(size[0] * 5);
                        glColor3f(0, 0, 0);
                        glViewport(0, 0, 300, 300);
                        glBegin(GL_POINTS);
                        {
                            for (GLfloat angle = 0; angle <= 2 * PI; angle += PI / 20.0)
                                glVertex3f(0.5 * cos(angle), 0.5 * sin(angle), 0);
                        }
                        glEnd();
                        glFlush();
                    });
    glutMainLoop();
}

/**
 * gl의 선 그리기
 */
TEST(CHAPTER09, code9_11)
{
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA);
    glutInitWindowSize(300, 300);
    glutInitWindowPosition(0, 0);
    glutCreateWindow(TEST_NAME);
    glClearColor(1.0, 1.0, 1.0, 1.0);
    glutDisplayFunc([]()
                    {
                        GLint scaleFactor = 1;
                        GLushort pattern = 0x00ff;
                        glClear(GL_COLOR_BUFFER_BIT);
                        glColor3f(0, 0, 0);
                        glLineWidth(3);
                        glViewport(0, 0, 300, 300);
                        glEnable(GL_LINE_STIPPLE);
                        {
                            for (GLfloat height = -0.9; height <= 0.9; height += 0.4)
                            {
                                glLineStipple(scaleFactor, pattern);
                                glBegin(GL_LINES);
                                {
                                    glVertex3f(-1, height, 0);
                                    glVertex3f(1, height, 0);
                                }
                                glEnd();
                                scaleFactor *= 2;
                            }
                        }
                        glDisable(GL_LINE_STIPPLE);
                        glFlush();
                    });
    glutMainLoop();
}

/**
 * 선분의 색 보간
 */
TEST(CHAPTER09, code9_12)
{
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA);
    glutInitWindowSize(300, 300);
    glutInitWindowPosition(0, 0);
    glutCreateWindow(TEST_NAME);
    glClearColor(1.0, 1.0, 1.0, 1.0);
    glutDisplayFunc([]()
                    {
                        glClear(GL_COLOR_BUFFER_BIT);
                        glLineWidth(10);
                        glViewport(0, 0, 300, 300);
                        glBegin(GL_LINES);
                        {
                            glColor3f(0, 1, 0);
                            glVertex3f(-1, 0, 0);
                            glColor3f(0, 0, 0);
                            glVertex3f(1, 0, 0);
                        }
                        glEnd();
                        glFlush();
                    });
    glutMainLoop();
}

/**
 * 선형보간으로 다각형 채움
 */
TEST(CHAPTER09, code9_13)
{
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA);
    glutInitWindowSize(300, 300);
    glutInitWindowPosition(0, 0);
    glutCreateWindow(TEST_NAME);
    glClearColor(1.0, 1.0, 1.0, 1.0);
    glutDisplayFunc([]()
                    {
                        glClear(GL_COLOR_BUFFER_BIT);
                        glViewport(0, 0, 300, 300);
                        glShadeModel(GL_SMOOTH);
                        glBegin(GL_TRIANGLES);
                        {
                            glColor3f(0, 1, 0);
                            glVertex3f(-.5, -.5, 0);
                            glColor3f(0, 0, 1);
                            glVertex3f(0.5, -.5, 0);
                            glColor3f(1, 0, 0);
                            glVertex3f(0, 0.5, 0);
                        }
                        glEnd();
                        glFlush();
                    });
    glutMainLoop();
}

/**
 * 안티 애일리싱
 */
TEST(CHAPTER09, code9_14)
{
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA);
    glutInitWindowSize(300, 300);
    glutInitWindowPosition(0, 0);
    glutCreateWindow(TEST_NAME);
    glClearColor(1.0, 1.0, 1.0, 1.0);
    glutDisplayFunc([]()
                    {
                        glClear(GL_COLOR_BUFFER_BIT);
                        glViewport(0, 0, 300, 300);
                        glColor3f(0, 0, 0);
                        glEnable(GL_BLEND); // 혼합 기능 활성
                        glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA); // 혼합 모드 설정
                        glEnable(GL_POINT_SMOOTH); // 부드러운 점 기능 활성
                        glHint(GL_POINT_SMOOTH_HINT, GL_NICEST); // 성능보다 퀄리티 우선으로 적용
                        glPointSize(12);
                        glBegin(GL_POINTS);
                        {
                            glVertex3f(-0.9, -0.65, 0);
                        }
                        glEnd();
                        glDisable(GL_POINT_SMOOTH);

                        glEnable(GL_LINE_SMOOTH);
                        glBegin(GL_LINES);
                        {
                            glVertex3f(-1, -.6, 0);
                            glVertex3f(1, -2, 0);
                            glVertex3f(-1, -.6, 0);
                            glVertex3f(0.75, 1, 0);
                            glVertex3f(-1, -.6, 0);
                            glVertex3f(-.75, 1, 0);
                        }
                        glEnd();
                        glDisable(GL_LINE_SMOOTH);
                        glDisable(GL_BLEND);
                        glFlush();
                    });
    glutMainLoop();
}