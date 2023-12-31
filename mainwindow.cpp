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

//funciones que reciben las señales para las clases, señal triggered, clase MainWindow
void MainWindow::on_actionNew_triggered()//Eliminar
{
    currentFile.clear(); //Eliminina el contenido de la variabe CurrentFile
    ui->textEdit->setText(QString());//Accede al objeto textEdit por el puntero ui y através del método
}                                    //setText le manda una cadena vacía

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
    ui->textEdit->setText(text);//Lo mustra el objeto TextEdit
    file.close();//Se cierra el archivo
}

void MainWindow::on_actionSave_as_triggered()
{
    // Display a dialog to choose the format
    QStringList formats;
    formats << "ODF Text Document (*.odt)" << "Plain Text (*.txt)" << "HTML Document (*.html)" << "Markdown Document (*.md)";
    QString selectedFormat = QFileDialog::getSaveFileName(this, "Choose format", currentFile, formats.join(";;"));


    if (selectedFormat.isEmpty()) {
        return;  // User canceled the operation
    }

    QFile file(selectedFormat);

    if (!file.open(QFile::WriteOnly | QFile::Text)) {
        QMessageBox::warning(this, "Alerta", "No se pudo guardar el archivo: " + file.errorString());
        return;
    }

    // Update the current file and set the main window title to the chosen file name
    currentFile = selectedFormat;
    setWindowTitle(selectedFormat);

    // Get the QTextDocument from the QTextEdit
    QTextDocument *document = ui->textEdit->document();


    // Create a QTextDocumentWriter based on the chosen format
    QTextDocumentWriter writer(currentFile);

    if (selectedFormat.endsWith(".txt")) {
        writer.setFormat("plaintext");
    } else if (selectedFormat.endsWith(".html")) {
        writer.setFormat("HTML");
    } else if (selectedFormat.endsWith(".md")) {
        writer.setFormat("markdown");
    } else {
        writer.setFormat("ODF");
    }

    // Use QTextDocumentWriter to write the document to a file in the selected format
    if (!writer.write(document)) {
        QMessageBox::warning(this, "Alerta", "Error al escribir en el archivo: ");
        return;
    }

    file.close();
}


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

void MainWindow::on_pushButton_clicked()//Cursiva
{
    QTextCursor cursor = ui->textEdit->textCursor();//Lo mismo xd
    QTextCharFormat charFormat = cursor.charFormat();
    charFormat.setFontItalic(!charFormat.fontItalic());
    cursor.mergeCharFormat(charFormat);
    ui->textEdit->mergeCurrentCharFormat(charFormat);
}

void MainWindow::on_pushButton_2_clicked()//Negrita
{
    QTextCursor cursor = ui->textEdit->textCursor();
    QTextCharFormat charFormat = cursor.charFormat();
    charFormat.setFontWeight(charFormat.fontWeight() == QFont::Bold ? QFont::Normal : QFont::Bold);//Operador terniario
    cursor.mergeCharFormat(charFormat);
    ui->textEdit->mergeCurrentCharFormat(charFormat);
}

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

void MainWindow::on_pushButton_4_clicked()//Subrayado
{
    QTextCursor cursor = ui->textEdit->textCursor();
    QTextCharFormat charFormat = cursor.charFormat();

    charFormat.setFontUnderline(!charFormat.fontUnderline());

    cursor.mergeCharFormat(charFormat);
    ui->textEdit->mergeCurrentCharFormat(charFormat);
}


void MainWindow::on_pushButton_5_clicked()//Justificado
{
    QTextCursor cursor = ui->textEdit->textCursor();
    QTextBlockFormat blockFormat = cursor.blockFormat();

    blockFormat.setAlignment(Qt::AlignLeft);

    cursor.mergeBlockFormat(blockFormat);
    ui->textEdit->setTextCursor(cursor);
}

void MainWindow::on_pushButton_6_clicked()//Centrado
{
    QTextCursor cursor = ui->textEdit->textCursor();
    QTextBlockFormat blockFormat = cursor.blockFormat();

    blockFormat.setAlignment(Qt::AlignCenter);

    cursor.mergeBlockFormat(blockFormat);
    ui->textEdit->setTextCursor(cursor);
}

void MainWindow::on_pushButton_7_clicked()//Izquierda
{
    QTextCursor cursor = ui->textEdit->textCursor();
    QTextBlockFormat blockFormat = cursor.blockFormat();

    blockFormat.setAlignment(Qt::AlignRight);

    cursor.mergeBlockFormat(blockFormat);
    ui->textEdit->setTextCursor(cursor);
}
