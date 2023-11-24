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
