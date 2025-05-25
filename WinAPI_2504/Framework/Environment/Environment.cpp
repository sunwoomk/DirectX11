#include "Framework.h"
#include "Environment.h"

Environment::Environment()
{
	CreateProjection();
}

Environment::~Environment()
{
	delete viewBuffer;
	delete projectionBuffer;
}

void Environment::CreateProjection()
{
    viewBuffer = new MatrixBuffer();
    projectionBuffer = new MatrixBuffer();

    //Orthographic : ���ٰ��� ���� ������ü�� ����ü�� �����ϴ� ������ȯ
    Matrix projection = XMMatrixOrthographicOffCenterLH(0.0f, SCREEN_WIDTH, 0.0f, SCREEN_HEIGHT, -1.0f, 1.0f);

    viewBuffer->SetVS(1);

    projectionBuffer->Set(projection);
    projectionBuffer->SetVS(2);
}
