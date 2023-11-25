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

# Introducción
Con la ayuda de habilidades de programación dentro del ámbito académico fue posible desarrollar una aplicación la cual nos ayuda en la edición de texto mediante diferentes herramientas que nos aportan en la personalización de este. Utilizando la plataforma Qt Creator se nos facilitó implementar los conocimientos desarrollados en el semestre, utilizando así, conocimientos básicos de programación tales el lenguaje de programación C++ el cual implementamos dentro de nuestro proyecto para crear funciones que nos permitan realizar cambios a nuestro archivo, así como también permitir guardar nuestro archivo en diferentes formatos, imprimir, editar, etc. Todo esto con el fin de tener una mayor flexibilidad a la hora de realizar asignaciones y/o trabajos.


# ¿Qué hace el código?


# Explicacion de funciones
El código tiene diversas funciones con las que funciona xd

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
    ui->textEdit->setText(text);//Lo mustra el objeto TextEdit
    file.close();//Se cierra el archivo
}
```
```c++
void MainWindow::on_actionSave_as_triggered()
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
