#include "rrepch.h"
#include "OpenGLBuffer.h"

///////////////////////////////////////////////////////////////////////////
////////////////////////  VERTEX BUFFER //////////////////////////////////
/////////////////////////////////////////////////////////////////////////

OpenGLVertexBuffer::OpenGLVertexBuffer()
    : render_ID(0)
{
    glGenBuffers(1, &render_ID);
}

OpenGLVertexBuffer::~OpenGLVertexBuffer()
{
    glDeleteBuffers(1, &render_ID);
}

void OpenGLVertexBuffer::SetData(void* vertices, const unsigned int& vertSize)
{
    glBindBuffer(GL_ARRAY_BUFFER, render_ID);
    glBufferData(GL_ARRAY_BUFFER, vertSize, vertices, GL_STATIC_DRAW);
}

void OpenGLVertexBuffer::Bind() const
{
    glBindBuffer(GL_ARRAY_BUFFER, render_ID);
}

void OpenGLVertexBuffer::Unbind() const
{
    glBindBuffer(GL_ARRAY_BUFFER, 0);
}

///////////////////////////////////////////////////////////////////////////
////////////////////////  INDEX BUFFER ///////////////////////////////////
/////////////////////////////////////////////////////////////////////////

OpenGLIndexBuffer::OpenGLIndexBuffer()
    : render_ID(0)
{
    glGenBuffers(1, &render_ID);
}

OpenGLIndexBuffer::~OpenGLIndexBuffer()
{
    glDeleteBuffers(1, &render_ID);
}

void OpenGLIndexBuffer::SetData(void* indices, const unsigned int& indiSize)
{
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, render_ID);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, indiSize, indices, GL_STATIC_DRAW);
}

void OpenGLIndexBuffer::Bind() const
{
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, render_ID);

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);

    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(3 * sizeof(float)));
    glEnableVertexAttribArray(1);

    glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(6 * sizeof(float)));
    glEnableVertexAttribArray(2);

}

void OpenGLIndexBuffer::Unbind() const
{
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
}
