#include "lab_m1/Tema2/tema2.h"

#include <vector>
#include <string>
#include <iostream>

#include "lab_m1/lab4/transform3D.h"
#include "lab_m1/lab5/lab_camera.h"

using namespace std;
using namespace m1;

Tema2::Tema2()
{
}


Tema2::~Tema2()
{
}

void Tema2::CreateMesh(const char* name, const std::vector<VertexFormat>& vertices, const std::vector<unsigned int>& indices)
{
    unsigned int VAO = 0;
    glGenVertexArrays(1, &VAO);
    glBindVertexArray(VAO);

    unsigned int VBO = 0;
    // Create the VBO and bind it
    glGenBuffers(1, &VBO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);

    // Send vertices data into the VBO buffer
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices[0]) * vertices.size(), &vertices[0], GL_STATIC_DRAW);

    unsigned int IBO = 0;
    // Create the IBO and bind it
    glGenBuffers(1, &IBO);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, IBO);

    // Send indices data into the IBO buffer
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices[0]) * indices.size(), &indices[0], GL_STATIC_DRAW);

    // Set vertex position attribute
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(VertexFormat), 0);

    // Set vertex normal attribute
    glEnableVertexAttribArray(1);
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(VertexFormat), (void*)(sizeof(glm::vec3)));

    // Set texture coordinate attribute
    glEnableVertexAttribArray(2);
    glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, sizeof(VertexFormat), (void*)(2 * sizeof(glm::vec3)));

    // Set vertex color attribute
    glEnableVertexAttribArray(3);
    glVertexAttribPointer(3, 3, GL_FLOAT, GL_FALSE, sizeof(VertexFormat), (void*)(2 * sizeof(glm::vec3) + sizeof(glm::vec2)));
    // ========================================================================

    // Unbind the VAO

    // Check for OpenGL errors
    if (GetOpenGLError() == GL_INVALID_OPERATION)
    {
        cout << "\t[NOTE] : For students : DON'T PANIC! This error should go away when completing the tasks." << std::endl;
        cout << "\t[NOTE] : For developers : This happens because OpenGL core spec >=3.1 forbids null VAOs." << std::endl;
    }

    // Mesh information is saved into a Mesh object
    meshes[name] = new Mesh(name);
    meshes[name]->InitFromBuffer(VAO, static_cast<unsigned int>(indices.size()));
}

void Tema2::Init()
{
    polygonMode = GL_FILL;
    projectionMatrix = glm::perspective(RADIANS(60), window->props.aspectRatio, 0.01f, 200.0f);

    cam = new implemented::Camera();
    cam->Set(glm::vec3(0, 2, 3.5f), glm::vec3(0, 1, 0), glm::vec3(0, 1, 0));

    // Sets the resolution of the small viewport
    glm::ivec2 resolution = window->GetResolution();
    miniViewportArea = ViewportArea(50, 50, resolution.x / 5.f, resolution.y / 5.f);
    
#pragma region Pista

#pragma region Puncte Pista
    std::vector<VertexFormat> vertices;
    vertices.push_back(VertexFormat(glm::vec3(-5.55, 0, 6.46), glm::vec3(1,1,1)));
    vertices.push_back(VertexFormat(glm::vec3(-5.88, 0, 5.69), glm::vec3(1,1,1)));
    vertices.push_back(VertexFormat(glm::vec3(-5.88, 0, 4.77), glm::vec3(1,1,1)));
    vertices.push_back(VertexFormat(glm::vec3(-5.62, 0, 3.99), glm::vec3(1,1,1)));
    vertices.push_back(VertexFormat(glm::vec3(-5.14, 0, 3.18), glm::vec3(1,1,1)));
    vertices.push_back(VertexFormat(glm::vec3(-4.63, 0, 2.37), glm::vec3(1,1,1)));
    vertices.push_back(VertexFormat(glm::vec3(-4.41, 0, 1.49), glm::vec3(1,1,1)));
    vertices.push_back(VertexFormat(glm::vec3(-4.55, 0, 0.61), glm::vec3(1,1,1)));
    vertices.push_back(VertexFormat(glm::vec3(-5.11, 0, -0.42), glm::vec3(1,1,1)));
    vertices.push_back(VertexFormat(glm::vec3(-5.59, 0, -1.08), glm::vec3(1,1,1)));
    vertices.push_back(VertexFormat(glm::vec3(-6.32, 0, -1.82), glm::vec3(1,1,1)));
    vertices.push_back(VertexFormat(glm::vec3(-6.91, 0, -2.48), glm::vec3(1,1,1)));
    vertices.push_back(VertexFormat(glm::vec3(-7.06, 0, -3.25), glm::vec3(1,1,1)));
    vertices.push_back(VertexFormat(glm::vec3(-6.91, 0, -4.11), glm::vec3(1,1,1)));
    vertices.push_back(VertexFormat(glm::vec3(-6.18, 0, -4.88), glm::vec3(1,1,1)));
    vertices.push_back(VertexFormat(glm::vec3(-5.25, 0, -4.84), glm::vec3(1,1,1)));
    vertices.push_back(VertexFormat(glm::vec3(-4.22, 0, -4.69), glm::vec3(1,1,1)));
    vertices.push_back(VertexFormat(glm::vec3(-3.04, 0, -4.4), glm::vec3(1,1,1)));
    vertices.push_back(VertexFormat(glm::vec3(-2.34, 0, -4.21), glm::vec3(1,1,1)));
    vertices.push_back(VertexFormat(glm::vec3(-1.31, 0, -3.99), glm::vec3(1,1,1)));
    vertices.push_back(VertexFormat(glm::vec3(-0.52, 0, -4.05), glm::vec3(1,1,1)));
    vertices.push_back(VertexFormat(glm::vec3(-0.54, 0, -4.73), glm::vec3(1,1,1)));
    vertices.push_back(VertexFormat(glm::vec3(-0.95, 0, -5.54), glm::vec3(1,1,1)));
    vertices.push_back(VertexFormat(glm::vec3(-1.06, 0, -6.54), glm::vec3(1,1,1)));
    vertices.push_back(VertexFormat(glm::vec3(-0.81, 0, -7.35), glm::vec3(1,1,1)));
    vertices.push_back(VertexFormat(glm::vec3(-0.41, 0, -7.9), glm::vec3(1,1,1)));
    vertices.push_back(VertexFormat(glm::vec3(0.27, 0, -8.46), glm::vec3(1,1,1)));
    vertices.push_back(VertexFormat(glm::vec3(1.22, 0, -8.62), glm::vec3(1,1,1)));
    vertices.push_back(VertexFormat(glm::vec3(2.19, 0, -8.26), glm::vec3(1,1,1)));
    vertices.push_back(VertexFormat(glm::vec3(2.76, 0, -7.63), glm::vec3(1,1,1)));
    vertices.push_back(VertexFormat(glm::vec3(3.12, 0, -6.92), glm::vec3(1,1,1)));
    vertices.push_back(VertexFormat(glm::vec3(3.19, 0, -6.08), glm::vec3(1,1,1)));
    vertices.push_back(VertexFormat(glm::vec3(3.05, 0, -5.36), glm::vec3(1,1,1)));
    vertices.push_back(VertexFormat(glm::vec3(2.71, 0, -4.82), glm::vec3(1,1,1)));
    vertices.push_back(VertexFormat(glm::vec3(2.31, 0, -4.25), glm::vec3(1,1,1)));
    vertices.push_back(VertexFormat(glm::vec3(2.64, 0, -3.61), glm::vec3(1,1,1)));
    vertices.push_back(VertexFormat(glm::vec3(3.49, 0, -3.46), glm::vec3(1,1,1)));
    vertices.push_back(VertexFormat(glm::vec3(4.2, 0, -3.55), glm::vec3(1,1,1)));
    vertices.push_back(VertexFormat(glm::vec3(5.03, 0, -3.55), glm::vec3(1,1,1)));
    vertices.push_back(VertexFormat(glm::vec3(5.93, 0, -3.25), glm::vec3(1,1,1)));
    vertices.push_back(VertexFormat(glm::vec3(6.67, 0, -2.69), glm::vec3(1,1,1)));
    vertices.push_back(VertexFormat(glm::vec3(7.17, 0, -1.89), glm::vec3(1,1,1)));
    vertices.push_back(VertexFormat(glm::vec3(7.61, 0, -1.19), glm::vec3(1,1,1)));
    vertices.push_back(VertexFormat(glm::vec3(7.69, 0, -0.58), glm::vec3(1,1,1)));
    vertices.push_back(VertexFormat(glm::vec3(7.74, 0, 0), glm::vec3(1,1,1)));
    vertices.push_back(VertexFormat(glm::vec3(7.51, 0, 0.69), glm::vec3(1,1,1)));
    vertices.push_back(VertexFormat(glm::vec3(7.05, 0, 1.23), glm::vec3(1,1,1)));
    vertices.push_back(VertexFormat(glm::vec3(6.41, 0, 1.71), glm::vec3(1,1,1)));
    vertices.push_back(VertexFormat(glm::vec3(5.6, 0, 1.82), glm::vec3(1,1,1)));
    vertices.push_back(VertexFormat(glm::vec3(4.62, 0, 1.58), glm::vec3(1,1,1)));
    vertices.push_back(VertexFormat(glm::vec3(3.67, 0, 1.23), glm::vec3(1,1,1)));
    vertices.push_back(VertexFormat(glm::vec3(2.86, 0, 0.93), glm::vec3(1,1,1)));
    vertices.push_back(VertexFormat(glm::vec3(2.03, 0, 0.75), glm::vec3(1,1,1)));
    vertices.push_back(VertexFormat(glm::vec3(1.2, 0, 0.6), glm::vec3(1,1,1)));
    vertices.push_back(VertexFormat(glm::vec3(0.28, 0, 0.75), glm::vec3(1,1,1)));
    vertices.push_back(VertexFormat(glm::vec3(-0.42, 0, 1.14), glm::vec3(1,1,1)));
    vertices.push_back(VertexFormat(glm::vec3(-0.66, 0, 1.73), glm::vec3(1,1,1)));
    vertices.push_back(VertexFormat(glm::vec3(-0.34, 0, 2.3), glm::vec3(1,1,1)));
    vertices.push_back(VertexFormat(glm::vec3(0.25, 0, 2.56), glm::vec3(1,1,1)));
    vertices.push_back(VertexFormat(glm::vec3(0.93, 0, 2.51), glm::vec3(1,1,1)));
    vertices.push_back(VertexFormat(glm::vec3(1.68, 0, 2.71), glm::vec3(1,1,1)));
    vertices.push_back(VertexFormat(glm::vec3(2.30, 0, 3.01), glm::vec3(1,1,1)));
    vertices.push_back(VertexFormat(glm::vec3(2.72, 0, 3.48), glm::vec3(1,1,1)));
    vertices.push_back(VertexFormat(glm::vec3(2.81, 0, 4.08), glm::vec3(1,1,1)));
    vertices.push_back(VertexFormat(glm::vec3(2.39, 0, 4.67), glm::vec3(1,1,1)));
    vertices.push_back(VertexFormat(glm::vec3(1.82, 0, 5), glm::vec3(1,1,1)));
    vertices.push_back(VertexFormat(glm::vec3(0.96, 0, 4.94), glm::vec3(1,1,1)));
    vertices.push_back(VertexFormat(glm::vec3(0.19, 0, 4.85), glm::vec3(1,1,1)));
    vertices.push_back(VertexFormat(glm::vec3(-0.48, 0, 4.94), glm::vec3(1,1,1)));
    vertices.push_back(VertexFormat(glm::vec3(-1.17, 0, 5.21), glm::vec3(1,1,1)));
    vertices.push_back(VertexFormat(glm::vec3(-1.79, 0, 5.68), glm::vec3(1,1,1)));
    vertices.push_back(VertexFormat(glm::vec3(-2.48, 0, 6.28), glm::vec3(1,1,1)));
    vertices.push_back(VertexFormat(glm::vec3(-2.95, 0, 6.87), glm::vec3(1,1,1)));
    vertices.push_back(VertexFormat(glm::vec3(-3.46, 0, 7.23), glm::vec3(1,1,1)));
    vertices.push_back(VertexFormat(glm::vec3(-4.02, 0, 7.35), glm::vec3(1,1,1)));
    vertices.push_back(VertexFormat(glm::vec3(-4.85, 0, 7.05), glm::vec3(1,1,1)));

#pragma endregion

    std::vector<VertexFormat> newVertices;

    for (int i = 0; i < vertices.size() - 1; i++) {
        glm::vec3 p1, p2;
        p1 = vertices[i].position;
        p2 = vertices[i + 1].position;

        glm::vec3 D = p2 - p1;
        glm::vec3 P = glm::cross(D, glm::vec3(0, 1, 0));
        glm::vec3 R = p1 + 0.8f * glm::normalize(P);
        glm::vec3 A = p1 - 0.8f * glm::normalize(P);

        newVertices.push_back(VertexFormat(R, glm::vec3(0.12, 0.23, 0.15)));
        newVertices.push_back(VertexFormat(A, glm::vec3(0.12, 0.23, 0.15)));
    }

    std::vector<unsigned int> indices;

    for (int i = 0; i < vertices.size() * 2 - 4; i ++) {
        if (i % 2 == 0) {
            indices.push_back(i);
            indices.push_back(i + 2);
            indices.push_back(i + 1);
        }
        else {
            indices.push_back(i);
            indices.push_back(i + 1);
            indices.push_back(i + 2);
        }
    }

    indices.push_back(vertices.size() * 2 - 4);
    indices.push_back(0);
    indices.push_back(vertices.size() * 2 - 3);

    indices.push_back(vertices.size() * 2 - 3);
    indices.push_back(0);
    indices.push_back(1);

    CreateMesh("pista", newVertices, indices);

#pragma endregion

#pragma region Grass

    std::vector<VertexFormat> grassVertices;
    std::vector<unsigned int> grassIndices;

    grassVertices.push_back(VertexFormat(glm::vec3(-100, 0, -100), glm::vec3(0.18, 0.61, 0.26)));
    grassVertices.push_back(VertexFormat(glm::vec3(100, 0, -100), glm::vec3(0.18, 0.61, 0.26)));
    grassVertices.push_back(VertexFormat(glm::vec3(100, 0, 100), glm::vec3(0.18, 0.61, 0.26)));
    grassVertices.push_back(VertexFormat(glm::vec3(-100, 0, 100), glm::vec3(0.18, 0.61, 0.26)));

    grassIndices.push_back(0);
    grassIndices.push_back(1);
    grassIndices.push_back(2);

    grassIndices.push_back(0);
    grassIndices.push_back(2);
    grassIndices.push_back(3);

    Mesh* mesh = new Mesh("box");
    mesh->LoadMesh(PATH_JOIN(window->props.selfDir, RESOURCE_PATH::MODELS, "primitives"), "box.obj");
    meshes[mesh->GetMeshID()] = mesh;

    CreateMesh("grass", grassVertices, grassIndices);

#pragma endregion

#pragma region Trunk

    std::vector<VertexFormat> treeVertices;
    std::vector<unsigned int> treeIndices;

    treeVertices.push_back(VertexFormat(glm::vec3(0, 0, 0), glm::vec3(0.43, 0.27, 0.19)));
    treeVertices.push_back(VertexFormat(glm::vec3(0.7f, 0, 0), glm::vec3(0.43, 0.27, 0.19)));
    treeVertices.push_back(VertexFormat(glm::vec3(0.7f, 0, 0.7f), glm::vec3(0.43, 0.27, 0.19)));
    treeVertices.push_back(VertexFormat(glm::vec3(0, 0, 0.7f), glm::vec3(0.43, 0.27, 0.19)));

    treeVertices.push_back(VertexFormat(glm::vec3(0, 2.5f, 0), glm::vec3(0.43, 0.27, 0.19)));
    treeVertices.push_back(VertexFormat(glm::vec3(0.7f, 2.5f, 0), glm::vec3(0.43, 0.27, 0.19)));
    treeVertices.push_back(VertexFormat(glm::vec3(0.7f, 2.5f, 0.7f), glm::vec3(0.43, 0.27, 0.19)));
    treeVertices.push_back(VertexFormat(glm::vec3(0, 2.5f, 0.7f), glm::vec3(0.43, 0.27, 0.19)));

    // sides
    treeIndices.push_back(1);
    treeIndices.push_back(4);
    treeIndices.push_back(5);

    treeIndices.push_back(1);
    treeIndices.push_back(0);
    treeIndices.push_back(4);

    //
    treeIndices.push_back(4);
    treeIndices.push_back(0);
    treeIndices.push_back(6);

    treeIndices.push_back(0);
    treeIndices.push_back(2);
    treeIndices.push_back(6);

    //
    treeIndices.push_back(3);
    treeIndices.push_back(5);
    treeIndices.push_back(7);

    treeIndices.push_back(1);
    treeIndices.push_back(5);
    treeIndices.push_back(3);

    //
    treeIndices.push_back(2);
    treeIndices.push_back(5);
    treeIndices.push_back(6);

    treeIndices.push_back(2);
    treeIndices.push_back(3);
    treeIndices.push_back(5);

    CreateMesh("trunk", treeVertices, treeIndices);

#pragma endregion

}

void Tema2::FrameStart()
{
    // Clears the color buffer (using the previously set color) and depth buffer
    glClearColor(0, 0, 0, 1);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

void Tema2::RenderScene() {
    

    RenderMesh(meshes["pista"], shaders["VertexColor"], glm::scale(glm::mat4(1), glm::vec3(4,0,4)));
    RenderMesh(meshes["grass"], shaders["VertexColor"], glm::translate(glm::mat4(1), glm::vec3(0, -0.1, 0)));
    RenderMesh(meshes["trunk"], shaders["VertexColor"], glm::mat4(1));

    modelMatrix = glm::mat4(1);
    modelMatrix = glm::scale(glm::mat4(1), glm::vec3(2, 2, 2)) * modelMatrix;
    modelMatrix = glm::translate(glm::mat4(1), glm::vec3(0.3f, 3, 0.3f)) * modelMatrix;
    RenderMesh(meshes["box"], shaders["VertexNormal"], modelMatrix);

    modelMatrix = glm::mat4(1);
    modelMatrix = glm::scale(glm::mat4(1), glm::vec3(2, 2, 2)) * modelMatrix;
    modelMatrix = glm::rotate(glm::mat4(1), glm::radians(45.f), glm::vec3_up) * modelMatrix;
    modelMatrix = glm::translate(glm::mat4(1), glm::vec3(0.3f, 3, 0.3f)) * modelMatrix;
    RenderMesh(meshes["box"], shaders["VertexNormal"], modelMatrix);

    glm::vec3 v = cam->forward;
    float alfa = -atan2(v.z, v.x) + M_PI_2;

    modelMatrix = glm::mat4(1);
    modelMatrix = glm::scale(glm::mat4(1), glm::vec3(0.4, 0.4, 0.8)) * modelMatrix;
    modelMatrix = glm::rotate(glm::mat4(1), alfa, glm::vec3_up) * modelMatrix;
    modelMatrix = glm::translate(glm::mat4(1), cam->GetTargetPosition()) * modelMatrix;
    RenderMesh(meshes["box"], shaders["VertexNormal"], modelMatrix);

}

void Tema2::RenderMesh(Mesh* mesh, Shader* shader, const glm::mat4& modelMatrix)
{
    if (!mesh || !shader || !shader->program)
        return;

    // Render an object using the specified shader and the specified position
    shader->Use();
    glUniformMatrix4fv(shader->loc_view_matrix, 1, GL_FALSE, glm::value_ptr(cam->GetViewMatrix()));
    glUniformMatrix4fv(shader->loc_projection_matrix, 1, GL_FALSE, glm::value_ptr(projectionMatrix));
    glUniformMatrix4fv(shader->loc_model_matrix, 1, GL_FALSE, glm::value_ptr(modelMatrix));

    mesh->Render();
}

void Tema2::Update(float deltaTimeSeconds)
{
    glLineWidth(3);
    glPointSize(5);
    glPolygonMode(GL_FRONT_AND_BACK, polygonMode);

    // Sets the screen area where to draw
    glm::ivec2 resolution = window->GetResolution();
    glViewport(0, 0, resolution.x, resolution.y);

    RenderScene();

    glClear(GL_DEPTH_BUFFER_BIT);
    glViewport(miniViewportArea.x, miniViewportArea.y, miniViewportArea.width, miniViewportArea.height);

    // Render the scene again, in the new viewport
    RenderScene();
}

void Tema2::FrameEnd()
{
}

void Tema2::OnInputUpdate(float deltaTime, int mods)
{
    // Add transformation logic
    if (window->KeyHold(GLFW_KEY_W))
    {
        cam->MoveForward(deltaTime * 6);
    }
    if (window->KeyHold(GLFW_KEY_S))
    {
        cam->MoveForward(-deltaTime * 6);
    }
    if (window->KeyHold(GLFW_KEY_A))
    {
        cam->RotateThirdPerson_OY(deltaTime * 2);
    }
    if (window->KeyHold(GLFW_KEY_D))
    {
        cam->RotateThirdPerson_OY(-deltaTime * 2);
    }
}


void Tema2::OnKeyPress(int key, int mods)
{

}


void Tema2::OnKeyRelease(int key, int mods)
{
}


void Tema2::OnMouseMove(int mouseX, int mouseY, int deltaX, int deltaY)
{

}


void Tema2::OnMouseBtnPress(int mouseX, int mouseY, int button, int mods)
{

}


void Tema2::OnMouseBtnRelease(int mouseX, int mouseY, int button, int mods)
{

}


void Tema2::OnMouseScroll(int mouseX, int mouseY, int offsetX, int offsetY)
{
}


void Tema2::OnWindowResize(int width, int height)
{
}
