#include "endingDialog.h"
#include "ui_endingDialog.h"


EndingDialog::EndingDialog(QString finalText,Qt::GlobalColor color,QWidget *parent) :
    QDialog(parent),
    finalText(finalText),
    color(color),
    ui(new Ui::EndingDialog)
{
    ui->setupUi(this);
    ui->labelWinner->setText(finalText);
}

EndingDialog::~EndingDialog()
{
    delete ui;
}

void EndingDialog::on_pushButton_clicked()
{
    Game game = Game();
    Dialog *dialog = new Dialog(game);
    dialog->show();
    accept();
}


void EndingDialog::on_exitBt_clicked()
{
    accept();
}


