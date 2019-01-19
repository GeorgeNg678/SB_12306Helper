#include "dialog.h"
#include "ui_dialog.h"

int start = 0;

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::on_pushButton_2_clicked()
{
    save_checkbox_state(ui->checkBox->isChecked());

    accept();       //关闭Dialog窗口
    start = 1;
}

void Dialog::on_pushButton_clicked()
{
    save_checkbox_state(ui->checkBox->isChecked());

    system("");      //下载python2.7
    system("");      //下载environment.txt
    accept();        //安装完成后关闭窗口
    start = 1;
}

#if(0)
//该函数没什么用，仅用于学习system（）的使用及查看python版本
int Dialog::first_time_setup()
{
    FILE *fp;
    QString inform[10];
    QString target[] = "Pyhton 2.7";

    system("python --version > ./temp.txt && exit");
    fp = fopen("./temp.txt","r");
    fread(inform,1,10,fp);
    fclose(fp);

    if( ! strcmp(target,inform))
    {
        return 0;
    }
    else
    {
        return 1;
    }

}

//以下代码来源于官方文档，用于qt文件操作的学习
//写入数据到文件
    QFile data("output.txt");
    if (data.open(QFile::WriteOnly | QFile::Truncate)) {
        QTextStream out(&data);
        out << "Result: " << qSetFieldWidth(10) << left << 3.14 << 2.7;
        // writes "Result: 3.14      2.7       "
    }


//从文件读取数据
    QFile file("./test.txt");
    if(!file.open(QIODevice::ReadOnly)) //读取失败返回0
    {
         return;
    }
    QTextStream in(&file);      //该语句用于从file中读取数据保存在in中
    while(!in.atEnd())
    {
        QString onecount = in.readLine();
        QStringList userpwd = onecount.split(':');
        qDebug() << userpwd.at(0) << "--" << userpwd.at(1);
    }
    file.close();
#endif

void Dialog::save_checkbox_state(int arg1)
{
    QFile data("E:\\temp.txt");

    if(data.open(QFile::WriteOnly))
    {
        QTextStream out(&data);
        out << arg1;
        data.close();
    }
}
