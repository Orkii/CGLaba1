#CG Laba1

# Создание окна
```c++
Window::sizeX = 400; // Задание размеров окна
Window::sizeY = 400;
Window::posX = 100;  // Задание положения  окна
Window::posY = 100;
Window::init(argc, argv, RenderSceneCB) //
``` 

Инициализация
```c++
int Window::init(int argc, char** argv, void (*callback)()){
    glutInit(&argc, argv);             // Инициализация GLUT
    objs = new list<Drawable*>();
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);
    glutInitWindowSize(sizeX, sizeY);  // Размеры
    glutInitWindowPosition(posX, posY);// Положение
    glutCreateWindow("Laba1");         // Имя окна
    GLenum res = glewInit();           // Инициализация GLEW
    if (res != GLEW_OK){               // Проверка корректности
        printf("Error: '%s'\n", glewGetErrorString(res));
        return 1;
    }
    glutDisplayFunc(callback);         // Функция отрисовки
    return 0;
}
```
Функция отрисовки
```c++
void RenderSceneCB() {
    glClear(GL_COLOR_BUFFER_BIT);       //Очистка буфера

    glColor3f(0.0f, 1.0f, 1.0f);        // Цвет

    glEnableVertexAttribArray(0);       // Отрисовка
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0);
    glDrawArrays(GL_TRIANGLES, 0, 3);
    glDisableVertexAttribArray(0);

    Window::paint();                    // Отрисовка

    glutSwapBuffers();
}
```
#Фигуры
##Точка
Создание точки
```c++
glm::vec3 v1(0.5f, 0.5f, 0.0f);
Window::add(new Point(v1));
```
```c++
Point::Point(glm::vec3 &v){
    glGenBuffers(1, &VBO);                                        // Создание буфера
    glBindBuffer(GL_ARRAY_BUFFER, VBO);                           // Настройка, хранит массив вершин
    glBufferData(GL_ARRAY_BUFFER, sizeof(v), &v, GL_STATIC_DRAW); // Задание вершин
}
```
Рисование точки
```c++
glEnableVertexAttribArray(0);
glBindBuffer(GL_ARRAY_BUFFER, VBO);                    // Привязываем буфер
glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0); // Как воспринимать данные внутри буфера
glDrawArrays(GL_POINTS, 0, 1);                         // Отрисовка как точка
glDisableVertexAttribArray(0);                       
```
##Треугольник
Создание треугольника
```c++
glm::vec3 v[3];
v[0] = glm::vec3(-0.1f, -0.1f, 0.0f);
v[1] = glm::vec3(0.1f, -0.1f, 0.0f);
v[2] = glm::vec3(0.0f, 0.1f, 0.0f);

glGenBuffers(1, &VBO);
glBindBuffer(GL_ARRAY_BUFFER, VBO);
glBufferData(GL_ARRAY_BUFFER, sizeof(v), &v, GL_STATIC_DRAW);
```
Рисование треугольника
```c++
glEnableVertexAttribArray(0);
glBindBuffer(GL_ARRAY_BUFFER, VBO);
glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0);
glDrawArrays(GL_TRIANGLES, 0, 3);                       // Отрисовка как треугольник
glDisableVertexAttribArray(0);                    
```
