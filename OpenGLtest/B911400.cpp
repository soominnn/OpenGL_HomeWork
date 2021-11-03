#include "pch.h"
#include "B911400.h"
//spotlight 실행
void B911400::initialize()
{
	glEnable(GL_LIGHTING);	//조명 ON
	glEnable(GL_LIGHT3);	//LIGHT3 ON
	GLfloat light_position3[] = { 1.0f, 1.0f, 1.0f, 1.0f };	//조명 위치 지정
	glLightfv(GL_LIGHT3, GL_POSITION, light_position3);
	GLfloat light_ambient2[] = { 4.0f, 4.0f, 4.0f, 4.0f };	//ambient 값 지정
	glLightfv(GL_LIGHT3, GL_AMBIENT, light_ambient2);
	GLfloat light_spot_direction[] = { -1.0f,-1.0f,-1.0f };	//빛의 방향 지정
	glLightf(GL_LIGHT3, GL_SPOT_CUTOFF, 1.0f); //cone의 앵글
	glLightf(GL_LIGHT3, GL_SPOT_EXPONENT, 10.0f); //concentration 
	glLightfv(GL_LIGHT3, GL_SPOT_DIRECTION, light_spot_direction);
	glEnable(GL_COLOR_MATERIAL); //기본 도형의 색상 유지
}
//앞선 조명 2개 끄기
void B911400::destroy()
{
	glDisable(GL_LIGHTING);
	glDisable(GL_LIGHT1); 
	glDisable(GL_LIGHT5);
}

//구현
void	B911400::drawSphere()
{
	//초록색으로 x축 그리기
	glColor3f(0.0f, 1.0f, 0.0f);
	glBegin(GL_LINE_LOOP);	//선 긋기
	glVertex3f(10.0f, 0.0f, 0.0f);
	glVertex3f(-10.0f, 0.0f, 0.0f);
	glEnd();

	//빨간색으로 y축 그리기
	glColor3f(1.0f, 0.0f, 0.0f);
	glBegin(GL_LINE_LOOP);	//선 긋기
	glVertex3f(0.0f, 10.0f, 0.0f);
	glVertex3f(0.0f, -10.0f, 0.0f);
	glEnd();

	//파란색으로 z축 그리기
	glColor3f(0.0f, 0.0f, 1.0f);
	glBegin(GL_LINE_LOOP);	//선 긋기
	glVertex3f(0.0f, 0.0f, 10.0f);
	glVertex3f(0.0f, 0.0f, -10.0f);
	glEnd();



	//정육면체의 front면 TRIANGLE_FAN으로 두 삼각형을 가지고 그리기(각 변의 길이:1)
	glBegin(GL_TRIANGLE_FAN);	//TRIANGLE_FAN 실행
	glColor3f(0.0f, 0.0f, 0.6f);	//색상 지정
	glVertex3f(0.5f, 0.5f, 0.5f);
	glVertex3f(-0.5f, 0.5f, 0.5f);
	glVertex3f(-0.5f, -0.5f, 0.5f);
	glVertex3f(0.5f, -0.5f, 0.5f);
	glEnd();
	//정육면체의 left면 TRIANGLE_FAN으로 두 삼각형을 가지고 그리기(각 변의 길이:1)
	glBegin(GL_TRIANGLE_FAN);	//TRIANGLE_FAN 실행
	glColor3f(0.0f, 0.0f, 0.6f);	//색상 지정
	glVertex3f(-0.5f, 0.5f, 0.5f);
	glVertex3f(-0.5f, 0.5f, -0.5f);
	glVertex3f(-0.5f, -0.5f, -0.5f);
	glVertex3f(-0.5f, -0.5f, 0.5f);
	glEnd();
	//정육면체의 right면 TRIANGLE_FAN으로 두 삼각형을 가지고 그리기(각 변의 길이:1)
	glBegin(GL_TRIANGLE_FAN);	//TRIANGLE_FAN 실행
	glColor3f(0.0f, 0.0f, 0.6f);	//색상 지정
	glVertex3f(0.5f, 0.5f, 0.5f);
	glVertex3f(0.5f, 0.5f, -0.5f);
	glVertex3f(0.5f, -0.5f, -0.5f);
	glVertex3f(0.5f, -0.5f, 0.5f);
	glEnd();
	//정육면체의 top면 TRIANGLE_FAN으로 두 삼각형을 가지고 그리기(각 변의 길이:1)
	glBegin(GL_TRIANGLE_FAN);	//TRIANGLE_FAN 실행
	glColor3f(0.0f, 0.0f, 0.6f);	//색상 지정
	glVertex3f(0.5f, 0.5f, 0.5f);
	glVertex3f(0.5f, 0.5f, -0.5f);
	glVertex3f(-0.5f, 0.5f, -0.5f);
	glVertex3f(-0.5f, 0.5f, 0.5f);
	glEnd();
	//정육면체의 bottom면 TRIANGLE_FAN으로 두 삼각형을 가지고 그리기(각 변의 길이:1)
	glBegin(GL_TRIANGLE_FAN);	//TRIANGLE_FAN 실행
	glColor3f(0.0f, 0.0f, 0.6f);	//색상 지정
	glVertex3f(0.5f, -0.5f, 0.5f);
	glVertex3f(0.5f, -0.5f, -0.5f);
	glVertex3f(-0.5f, -0.5f, -0.5f);
	glVertex3f(-0.5f, -0.5f, 0.5f);
	glEnd();
	//정육면체의 back면 TRIANGLE_FAN으로 두 삼각형을 가지고 그리기(각 변의 길이:1)
	glBegin(GL_TRIANGLE_FAN);	//TRIANGLE_FAN 실행
	glColor3f(0.0f, 0.0f, 0.6f);	//색상 지정
	glVertex3f(0.5f, 0.5f, -0.5f);
	glVertex3f(-0.5f, 0.5f, -0.5f);
	glVertex3f(-0.5f, -0.5f, -0.5f);
	glVertex3f(0.5f, -0.5f, -0.5f);
	glEnd();
	
	//조명 2개중 1번째 조명 설정
	glEnable(GL_LIGHTING);	//조명 ON
	glEnable(GL_LIGHT1);	//LIGHT1
	GLfloat light_position[] = { 0.0f, 0.0f, 1.0f, 1.0f };	//조명 위치 지정
	GLfloat light_ambient[] = { 5.0f, 5.0f, 5.0f, 5.0f };	//ambient값 설정
	glLightfv(GL_LIGHT1, GL_AMBIENT, light_ambient);
	glLightfv(GL_LIGHT1, GL_POSITION, light_position);

	//조명 2개중 2번째 조명 설정
	glEnable(GL_LIGHTING);	//조명 ON
	glEnable(GL_LIGHT5);	//LIGHT5
	GLfloat light_position2[] = { 3.0, 3.0, 6.0, 1.0 }; //조명 위치 지정
	GLfloat light_diffuse[] = { 5.0, 5.0, 5.0, 5.0 };	//diffuse값 설정
	GLfloat mat_diffuse[] = { 3.0,3.0,3.0,3.0 };	//material중 mat_diffuse값 설정
	glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);
	glLightfv(GL_LIGHT5, GL_DIFFUSE, light_diffuse);
	glLightfv(GL_LIGHT5, GL_POSITION, light_position2);

	//기본 도형의 색상 유지
	glEnable(GL_COLOR_MATERIAL);
	
	//앞선 조명 2개 끄기
	destroy();
	
	//spotlight 실행
	initialize();

	return;
}

