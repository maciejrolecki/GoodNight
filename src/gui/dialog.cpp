#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(Game& game,QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog),
    game(game)

{
    ui->setupUi(this);
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::on__sendBt_clicked()
{
    GameWindow *gameplay = new GameWindow(game,(size_t)(ui->_slider->value()),nullptr,50);

    gameplay->show();
    accept();
}



