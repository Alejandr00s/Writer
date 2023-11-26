# Nombre
Alejandro Osorio Osorio  
Samuel Parra Murillo
# Institución
Universidad tecnológica de Pereira
# Programa
Ingeniería de Sistemas y Computación
# Facultad
Facultad de Ingenierías
# Matería
Programacion II
# Correo
alejandro.osorio3@utp.edu.co  
samuel.parra@utp.edu.co

# Introducción
Con la ayuda de habilidades de programación dentro del ámbito académico fue posible desarrollar una aplicación la cual nos ayuda en la edición de texto mediante diferentes herramientas que nos aportan en la personalización de este. Utilizando la plataforma Qt Creator se nos facilitó implementar los conocimientos desarrollados en el semestre, utilizando así, conocimientos básicos de programación tales el lenguaje de programación C++ el cual implementamos dentro de nuestro proyecto para crear funciones que nos permitan realizar cambios a nuestro archivo, así como también permitir guardar nuestro archivo en diferentes formatos, imprimir, editar, etc. Todo esto con el fin de tener una mayor flexibilidad a la hora de realizar asignaciones y/o trabajos.

# Descripción de su arquitectura
Nuestro código está dividido en diferentes categorías las cuales cumplen diferentes funciones dentro de nuestro programa. Ver Fig. 1.  

![Arquitectura](https://github.com/Alejandr00s/Writer/assets/127120995/7812d683-8734-4557-bceb-070193083cfd)

Fig. 1. Arquitectura y Secciones del Proyecto


Por un lado nos encontramos con una carpeta principal en la cual está ubicado nuestro proyecto, en nuestro caso es llamado Writer (1) el cual hace referencia a la escritura dentro de este.

Dentro de la carpeta Writer (1) podemos encontrar un archivo de texto llamado CMakeLists.txt (2) en el cual podemos encontrar las características del compilador CMake que utilizamos para nuestro proyecto y en el cual se encuentran valores como la versión, los lenguajes, los componentes, librerías y diferentes funciones que serán profundizadas más adelante.

A Continuación nos encontramos con la categoría Writer (3) el cual representa nuestro archivo ejecutable (*.exe) que hace referencia en sí a nuestro proyecto como tal.


Posteriormente nos encontramos con el archivo de encabezado Header Files (5). En el cual se incluyen los botones interactivos de nuestro proyecto y sus respectivas funciones, asimismo, en este apartado se incluyen las librerías propias de la plataforma Qt Creator la cual nos ayuda a adaptar nuestro código base para que sea compatible con la plataforma. Este apartado es definido dentro de nuestro proyecto como mainwindow.h (6) o también conocido como nuestro encabezado de la ventana principal (aplicación).

Siguiendo, nos encontramos con archivos de código fuente Source Files (7). Los cuales son la base de nuestra aplicación en el cual está definida la programación detrás del proyecto que asigna funciones con el fin del correcto funcionamiento del editor de texto.

Dentro de esta sección están los códigos C++ (*.cpp) tales como main.cpp (8) y mainwindow.cpp (9). Dentro del archivo main.cpp (8) se encuentran las características de la ventana principal, en el cual se incluyen argumentos, tamaño, clase y ejecución.

Dentro de mainwindow.cpp (9) se encuentra lo relacionado al código C++ un poco más avanzado ya que aquí es donde profundizamos en las funciones del editor de texto y asignamos condiciones para que nuestro texto no se corrompa o se dañe. Esta es la sección en donde se tiene un mayor desarrollo.

Luego tenemos nuestra interfaz llamada mainwindow.ui (10) el cual es básicamente nuestro programa en cuestión, dentro de la interfaz de usuario es donde incluimos botones, editores de texto (los cuales permiten cambiar la fuente de nuestro texto) y la hoja de desarrollo en el cual el usuario puede escribir libremente. Dentro de esta interfaz se tiene un parámetro más visual acerca de la funciones de nuestro código, lo cual nos permite entender de manera más clara la función de cada línea de código trabajada anteriormente.


Finalmente tenemos los módulos del compilador CMake asignados como CMake Modules (11) dentro de esta carpeta encontramos la dirección de nuestro compilador dentro del ordenador el cual nos permite ejecutar todo el código ya desarrollado con el fin de dar inicio y fin a nuestra aplicación.


# ¿Qué hace el código?
Dentro de nuestro proyecto, cada línea de código cumple una función muy importante dentro de este, desde personalización de botones hasta dictámenes para que el programa pueda funcionar de la mejor manera. 

Teniendo esto en cuenta podemos decir que nuestro código es multipropósito y que un cambio dentro de este puede generar diferentes modificaciones en nuestro archivo y aplicación.


# Explicacion de funciones
Como mencionamos anteriormente, el proyecto está divido en varias secciones y cada una de estas cumplen un rol en específico para el correcto funcionamiento del editor de texto. Empezaremos por la primera sección de código: CMakeLists.txt (2).

Una vez dentro del código vemos las siguientes líneas:
```CMake
cmake_minimum_required(VERSION 3.5)

project(Writer VERSION 0.1 LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets PrintSupport)

set(PROJECT_SOURCES
        main.cpp
        mainwindow.cpp
        mainwindow.h
        mainwindow.ui
)
```
Como se mencionó anteriormente, el archivo CMakeLists.txt compone las características del compilador CMake, incluyendo versiones que en nuestro caso es la versión 3.5, versión del proyecto 0.1 y el lenguaje de programación C++ compatible a Qt creator.  

También se encuentran los recursos del compilador, entre estos están los paquetes de componentes que nos ayudan a realizar diferentes tareas a través de la aplicación.

Dentro del archivo CMakeLists.txt se evidencias las fuentes de que componen nuestro proyectos las cuales son las secciones que explicamos anteriormente.
````CMake
if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(Writer
        MANUAL_FINALIZATION
        ${PROJECT_SOURCES}
    )
# Define target properties for Android with Qt 6 as:
#    set_property(TARGET Writer APPEND PROPERTY QT_ANDROID_PACKAGE_SOURCE_DIR
#                 ${CMAKE_CURRENT_SOURCE_DIR}/android)
# For more information, see https://doc.qt.io/qt-6/qt-add-executable.html#target-creation
else()
    if(ANDROID)
        add_library(Writer SHARED
            ${PROJECT_SOURCES}
        )
# Define properties for Android with Qt 5 after find_package() calls as:
#    set(ANDROID_PACKAGE_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/android")
    else()
        add_executable(Writer
            ${PROJECT_SOURCES}
        )
    endif()
endif()

target_link_libraries(Writer PRIVATE Qt${QT_VERSION_MAJOR}::Widgets PRIVATE Qt${QT_VERSION_MAJOR}::PrintSupport)
````
Adentrándonos en el código, se presenta una función compuesta de características del proyecto, tales como propiedades del ejecutable (*.exe), inclusión de librerías y compatibilidad de impresión.

````CMake
# Qt for iOS sets MACOSX_BUNDLE_GUI_IDENTIFIER automatically since Qt 6.1.
# If you are developing for iOS or macOS you should consider setting an
# explicit, fixed bundle identifier manually though.
if(${QT_VERSION} VERSION_LESS 6.1.0)
  set(BUNDLE_ID_OPTION MACOSX_BUNDLE_GUI_IDENTIFIER com.example.Writer)
endif()
set_target_properties(Writer PROPERTIES
    ${BUNDLE_ID_OPTION}
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

include(GNUInstallDirs)
install(TARGETS Writer
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

if(QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(Writer)
endif()
````
Finalmente se define una función dependiente de la versión de Qt Creator que tengamos instalada con el fin de instalar los componentes y librerías necesarias para el correcto funcionamiento de la aplicación.

La siguiente sección sería mainwindow.h (6) o también conocida como encabezado de la ventana principal.
````c++
#ifndef MAINWINDOW_H
#define MAINWINDOW_H
//librerias necesarias
#include <QMainWindow>//clase proporcionada por Qt para la creación de ventanas principales de la aplicación.
#include <QFile>//funcionalidad para trabajar con archivos en Qt.
#include <QFileDialog>//cuadros de diálogo de selección de archivos y directorios.
#include <QTextStream>//facilita la lectura y escritura de texto en archivos o dispositivos de datos
#include <QMessageBox>//permite mostrar cuadros de diálogo de mensajes al usuario
#include <QtPrintSupport/QPrinter>//se utiliza para configurar la impresión en aplicaciones Qt
#include <QtPrintSupport/QPrintDialog>//proporciona un cuadro de diálogo de impresión estándar en Qt
#include <QTextDocumentWriter>//Para guardar los archivos
````
Dentro de la sección encabezado están incluidas las librerías utilizadas en nuestro proyecto de Qt creator, aqui se define en encabezado de la ventana principal y se incluye la interfaz de usuario explicada anteriormente. Dentro de esta sección se incluyen características públicas (ventana principal) y privadas (botones, funciones, etc.) de nuestro proyecto.

````c++
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_actionNew_triggered();//Eliminar

    void on_actionOpen_triggered();//Abrir

    void on_actionSave_as_triggered();//Guardar

    void on_actionPrint_triggered();//Imprimir

    void on_fontComboBox_currentFontChanged(const QFont &f);//fuentes

    void on_spinBox_valueChanged(int arg1);//Tamaño de letra

    void on_pushButton_clicked();//Cursiva

    void on_pushButton_2_clicked();//Negrita

    void on_pushButton_3_clicked();//Resaltado

    void on_pushButton_4_clicked();//Subrayado

    void on_pushButton_5_clicked();//justificado

    void on_pushButton_6_clicked();//Centrado

    void on_pushButton_7_clicked();//Izquierda

private:
    Ui::MainWindow *ui;
    QString currentFile = "";
};
#endif // MAINWINDOW_H
````
Dentro de la sección de código fuente encontramos 2 archivos, main.cpp (8) y mainwindow.cpp (9).

Para main.cpp (8): Dentro de este archivo está definida la ventana principal sin contenido, la cual recibe diferentes argumentos conforme el usuario le da uso, también posee la característica de abrir en pantalla completa para mayor comodidad.
````c++
#include "mainwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.showMaximized();//se muestra maximizada
    return a.exec();
}
````
Para mainwindow.cpp (9): Este es el archivo en el que utilizamos nuestro conocimiento en programación adaptado al programa Qt Creator, dentro de este relacionamos los aspectos de la interfaz del usuario y las funciones de cada herramienta y establecemos una relación de parentesco (parent).
````c++
#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}
````
Iniciando con las funciones, empezamos con la función “New” el cual nos permite limpiar nuestra hoja de escritura para así dar paso a un nuevo inicio, está definida por currentFile.Clear() la cual borra el contenido de la hoja de escritura y la deja limpia a la par de setText(Qstring())

Nuestra siguiente función es “Open” la cual abre un archivo que ya tengamos guardado dentro de nuestro dispositivo con el fin de dar edición y/o correcciones. Primeramente se toma el nombre del archivo y se agrega una condición que permite abrir el archivo y si no se puede (ya sea porque ya está abierto o simplemente no es compatible) lanza una alerta de error. Con esto se toma la información del archivo y se transcribe en la aplicación con ayuda de in.readAll() y setText(text).

```c++
void MainWindow::on_actionNew_triggered()//Eliminar
{
    currentFile.clear(); //Eliminina el contenido de la variabe CurrentFile
    ui->textEdit->setText(QString());//Accede al objeto textEdit por el puntero ui y através del método
}
```
```c++
void MainWindow::on_actionOpen_triggered()//Abrir
{
    QString fileName = QFileDialog::getOpenFileName(this, "Abrir archivo ODF", QString(), "Documentos ODF (*.odt *.ods *.odp);;Todos los archivos (*.*);;");
    //diálogo de selección de archivo. Guarda el nombre de la variable
    QFile file(fileName);//Crea un nuevo archivo con el nombre de la variable
    currentFile = fileName; //Actualiza la variable actual
    if (!file.open(QIODevice::ReadOnly | QFile::Text)){//verifica que si el archivo no se pudo abrir
        QMessageBox::warning(this,"Alerta","No se pudo abrir el archivo: "+file.errorString());
        return;//se sale de la función
    }
    setWindowTitle(fileName);//pone el nombre del archivo como el de la ventana
    QTextStream in(&file);//Abre el archivo
    QString text = in.readAll();//Lee el archivo
    ui->textEdit->setText(text);//Lo muestra en el objeto TextEdit
    file.close();//Se cierra el archivo
}
```
Ahora tenemos la función “Guardar” el cual nos permite como su nombre lo indica, guardar nuestro archivo de texto en diferentes formatos, ya sea (*.txt), (*.html), (*.odp), etc. Para esta función se toma el nombre del archivo y se le asigna un lugar en nuestro dispositivo, en caso de que no se pueda guardar saldrá una alerta que indique que no puede guardarse el archivo.
```c++
void MainWindow::on_actionSave_as_triggered()//Guardar
{
    QStringList formats;//Crea una nueva lista con los formatos de texto
    formats << "ODF Text Document (*.odt)" << "Plain Text (*.txt)" << "HTML Document (*.html)" << "Markdown Document (*.md)";
    QString selectedFormat = QFileDialog::getSaveFileName(this, "Choose format", currentFile, formats.join(";;"));//Selecciona el tipo de formato


    if (selectedFormat.isEmpty()) {
        return;//Por si se cancela el diálogo de selección
    }

    QFile file(selectedFormat);//Crea un nuevo archivo con el formato seleccionado

    if (!file.open(QFile::WriteOnly | QFile::Text)) {
        QMessageBox::warning(this, "Alerta", "No se pudo guardar el archivo: " + file.errorString());
        return;
    }//Mensaje de error por si ocurre un error

    currentFile = selectedFormat;//Actualiza el documento al cuál se esta trabajando
    setWindowTitle(selectedFormat);//Actualiza el nombre de la ventana con el nombre del archivo actual

    QTextDocument *document = ui->textEdit->document();//Crea un nuevo documento con el contenido del text edit

    QTextDocumentWriter writer(currentFile);//Crea un guardado del archivo actual

    if (selectedFormat.endsWith(".txt")) {
        writer.setFormat("plaintext");
    } else if (selectedFormat.endsWith(".html")) {
        writer.setFormat("HTML");
    } else if (selectedFormat.endsWith(".md")) {
        writer.setFormat("markdown");
    } else {
        writer.setFormat("ODF");
    }//permite guardar el archivo con el lenguaje seleccionado

    if (!writer.write(document)) {
        QMessageBox::warning(this, "Alerta", "Error al escribir en el archivo: ");
        return;
    }//Alerta por si no se pudo guardar el documento

    file.close();//cierra la instancia de guardado
}
```
La función “Print” nos permite mandar una señal hacia una impresora conectada con nuestro dispositivo con el fin de imprimir la hoja de texto que hayamos creado. Está definido por la función QPrinter la cual nos lleva a una interfaz con el fin de realizar una impresión con ciertas características.

También está la herramienta ComboBox en la cual se encuentran los diferentes tipos de fuentes que le queramos aplicar a nuestro texto seleccionado, todas ellas de tipo escalable y modificable.

```c++
void MainWindow::on_actionPrint_triggered()//Imprimir
{
    QPrinter printer; //crea una nueva impresora
    QPrintDialog pDialog(&printer, this);//apunta a la impresora sirve para configurar la impresión
    if(pDialog.exec() == QDialog::Rejected){//Error por si la impresora no funciona
        QMessageBox::warning(this, "Alerta","No se pudo abrir la impresora");
        return;
    }
    ui->textEdit->print(&printer);//Imprime lo que está dentro del objeto text edit
}
```
A Continuación, tenemos 3 herramientas que nos permiten personalizar el tamaño y tipo de letra, tenemos un spinBox que permite ajustar el tamaño del texto que hayamos seleccionado, toma el argumento y lo agranda a la escala que queramos. Para el tipo de letra tenemos cursiva y negrita, las cuales tal y como el spinBox, generan un cambio en nuestro texto seleccionado. 

```c++
void MainWindow::on_fontComboBox_currentFontChanged(const QFont &font)
{
    QTextCursor cursor = ui->textEdit->textCursor();
    QTextCharFormat charFormat = cursor.charFormat();

    // Keep the existing font size and only change the font family
    QFont newFont = charFormat.font();
    newFont.setFamily(font.family());

    charFormat.setFont(newFont);
    cursor.mergeCharFormat(charFormat);

    ui->textEdit->mergeCurrentCharFormat(charFormat);
}
```

```c++
void MainWindow::on_spinBox_valueChanged(int arg1)
{
    QTextCursor cursor = ui->textEdit->textCursor();

    if (!cursor.isNull() && cursor.hasSelection()) {
        QTextCharFormat charFormat = cursor.charFormat();
        QFont font = charFormat.font();

        // Change only the font size
        font.setPointSize(arg1);

        charFormat.setFont(font);
        cursor.mergeCharFormat(charFormat);
    }
}
```

```c++
void MainWindow::on_pushButton_clicked()//Cursiva
{
    QTextCursor cursor = ui->textEdit->textCursor();//Lo mismo xd
    QTextCharFormat charFormat = cursor.charFormat();
    charFormat.setFontItalic(!charFormat.fontItalic());
    cursor.mergeCharFormat(charFormat);
    ui->textEdit->mergeCurrentCharFormat(charFormat);
}
```

```c++
void MainWindow::on_pushButton_2_clicked()//Negrita
{
    QTextCursor cursor = ui->textEdit->textCursor();
    QTextCharFormat charFormat = cursor.charFormat();
    charFormat.setFontWeight(charFormat.fontWeight() == QFont::Bold ? QFont::Normal : QFont::Bold);//Operador terniario
    cursor.mergeCharFormat(charFormat);
    ui->textEdit->mergeCurrentCharFormat(charFormat);
}
```
Los siguientes botones juegan un papel similar a los dos anteriores, tienen la finalidad de subrayar o resaltar nuestro texto.

```c++
void MainWindow::on_pushButton_3_clicked()//Resaltado
{
    QTextCursor cursor = ui->textEdit->textCursor();
    QTextCharFormat charFormat = cursor.charFormat();


    if (charFormat.background().style() == Qt::NoBrush) {//NoBrush si no tiene fondo
        charFormat.setBackground(QBrush(Qt::green));
    } else {
        charFormat.setBackground(Qt::NoBrush);
    }

    cursor.mergeCharFormat(charFormat);
    ui->textEdit->mergeCurrentCharFormat(charFormat);
}
```

```c++
void MainWindow::on_pushButton_4_clicked()//Subrayado
{
    QTextCursor cursor = ui->textEdit->textCursor();
    QTextCharFormat charFormat = cursor.charFormat();

    charFormat.setFontUnderline(!charFormat.fontUnderline());

    cursor.mergeCharFormat(charFormat);
    ui->textEdit->mergeCurrentCharFormat(charFormat);
}
```
Los siguientes botones tienen la finalidad de alinear nuestro texto ya sea a la izquierda y justificado, al centro y a la derecha. Lo que hace esta función es bloquear el texto que tenemos en cierta posición con ayuda de QTextBlockFormat.
```c++
void MainWindow::on_pushButton_5_clicked()//Justificado
{
    QTextCursor cursor = ui->textEdit->textCursor();
    QTextBlockFormat blockFormat = cursor.blockFormat();

    blockFormat.setAlignment(Qt::AlignLeft);

    cursor.mergeBlockFormat(blockFormat);
    ui->textEdit->setTextCursor(cursor);
}
```

```c++
void MainWindow::on_pushButton_6_clicked()//Centrado
{
    QTextCursor cursor = ui->textEdit->textCursor();
    QTextBlockFormat blockFormat = cursor.blockFormat();

    blockFormat.setAlignment(Qt::AlignCenter);

    cursor.mergeBlockFormat(blockFormat);
    ui->textEdit->setTextCursor(cursor);
}
```

```c++
void MainWindow::on_pushButton_7_clicked()//Izquierda
{
    QTextCursor cursor = ui->textEdit->textCursor();
    QTextBlockFormat blockFormat = cursor.blockFormat();

    blockFormat.setAlignment(Qt::AlignRight);

    cursor.mergeBlockFormat(blockFormat);
    ui->textEdit->setTextCursor(cursor);
}
```
# Manual tecnico
![imagen_1](https://github.com/Alejandr00s/Writer/assets/127120995/c79b262f-f027-4cfc-918d-72d717666ee1)
Una vez se ejecuta la aplicación, se obsrva el menú de la aplicación, en este se encuentran un panel en el cúal se puede escribir y tomar notas y en la parte superior se encuentran todas las opciones disponibles, a continuación, se explicaran todas las funciones que posee el programa.

![imagen_2](https://github.com/Alejandr00s/Writer/assets/127120995/ce43b3c2-d026-4116-b360-8bb811b7c623)

Lo primero que se encuentra en la parte superior izquierda es el menú, este menú despliega una serie de opciones que se enfocan principalmente en el archivo.

![imagen_2](https://github.com/Alejandr00s/Writer/assets/127120995/d92e197b-4900-4778-a80b-e0d3c3205c8a)
La primera opción es el eliminado, al hacer click en este botón, se borrara todo lo que este escrito en el panel de texto.


![imagen_2](https://github.com/Alejandr00s/Writer/assets/127120995/20999d77-8864-4aed-8532-046fd30419e0)
La segunda opción sirve para abrir el archivo con el cúal se va a trabajar, a tráves de un menú en el que se puede escoger el archivo especifico a emplear.

![imagen_2](https://github.com/Alejandr00s/Writer/assets/127120995/9ab550c1-b390-4633-99a9-674cb6f69f0a)

![imagen_2](https://github.com/Alejandr00s/Writer/assets/127120995/d547aaea-bb89-44de-a418-2693d73789af)



![imagen_3](https://github.com/Alejandr00s/Writer/assets/127120995/3158b9a3-c605-4fcf-8d92-bdcf8f46d1e0)

![imagen_4](https://github.com/Alejandr00s/Writer/assets/127120995/cdb68aa9-d448-477d-bbf6-3f2f98cfe832)

![imagen_5](https://github.com/Alejandr00s/Writer/assets/127120995/80049c8a-0caa-4f57-8069-9370260503f6)

![imagen_6](https://github.com/Alejandr00s/Writer/assets/127120995/c5392d34-5499-4447-b07d-c35e6333679d)

![imagen_1](https://github.com/Alejandr00s/Writer/assets/127120995/453a5768-d076-446b-9e67-447281b67327)

![imagen_1](https://github.com/Alejandr00s/Writer/assets/127120995/1075cb1b-9c78-4add-afa3-3f36077668bf)

![imagen_1](https://github.com/Alejandr00s/Writer/assets/127120995/b26a5ac7-5d78-41c7-9f21-ecd8cc708c7c)

![imagen_1](https://github.com/Alejandr00s/Writer/assets/127120995/05969cf7-30fa-425e-9416-b328c991da27)

![imagen_1](https://github.com/Alejandr00s/Writer/assets/127120995/74169529-986a-40e7-845f-8005f9b7338c)

