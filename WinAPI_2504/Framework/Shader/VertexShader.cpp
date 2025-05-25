#include "Framework.h"

VertexShader::VertexShader(wstring file)
{
    UINT flags = D3DCOMPILE_ENABLE_STRICTNESS | D3DCOMPILE_DEBUG;

    HRESULT result = D3DCompileFromFile(file.c_str(), nullptr, nullptr,
        "VS", "vs_5_0", flags, 0, &blob, nullptr);

    assert(SUCCEEDED(result));

    DEVICE->CreateVertexShader(blob->GetBufferPointer(), blob->GetBufferSize(),
        nullptr, &shader);

    CreateInputLayout();

    blob->Release();
}

VertexShader::~VertexShader()
{
    shader->Release();
}

void VertexShader::Set()
{
    DC->IASetInputLayout(inputLayout);
    DC->VSSetShader(shader, nullptr, 0);
}

void VertexShader::CreateInputLayout()
{
    D3D11_INPUT_ELEMENT_DESC layoutDesc[] =
    {
        {"POSITION", 0, DXGI_FORMAT_R32G32B32_FLOAT, 0, 0,
        D3D11_INPUT_PER_VERTEX_DATA, 0},    
        {"COLOR", 0, DXGI_FORMAT_R32G32B32A32_FLOAT, 0, 12,
        D3D11_INPUT_PER_VERTEX_DATA, 0}
    };

    UINT layoutSize = ARRAYSIZE(layoutDesc);

    DEVICE->CreateInputLayout(layoutDesc, layoutSize,
        blob->GetBufferPointer(), blob->GetBufferSize(), &inputLayout);
}
