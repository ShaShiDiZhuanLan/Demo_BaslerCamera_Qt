/*-------------------------------------------------
#
# Project created by QtCreator
# Author: 沙振宇
# CreateTime: 2017-12-14
# UpdateTime: 2019-12-31
# Info: Qt（C++）调用工业相机Basler的SDK使用示例
# Url:https://shazhenyu.blog.csdn.net/article/details/78844664
# Github:https://github.com/ShaShiDiZhuanLan/Demo_BaslerCamera_Qt
#
#-------------------------------------------------*/
#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();
}
