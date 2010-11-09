/*
 * Copyright (c) 2010 Petr Mrázek (peterix)
 * See LICENSE for details.
 */

#include <QtGui/QApplication>
#include "blankslade.h"


int main(int argc, char** argv)
{
    QApplication app(argc, argv);
    blankslade appGui;
    appGui.show();
    return app.exec();
}
