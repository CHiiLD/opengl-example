#include <gtest.h>
#include <GLUT/glut.h>

int main(int argc, char *argv[])
{
    glutInit(&argc, argv); // glut lib를 초기화하고 운영체제와 연결하여 세션을 형성
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}