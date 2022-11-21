#include "createblockform.h"
#include "ui_createblockform.h"
#include "transactionentry.h"

CreateBlockForm::CreateBlockForm(BlockChain<BLOCK_SIZE> *_bc, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::CreateBlockForm),
    bc(_bc)
{
    ui->setupUi(this);
    connect(ui->buttonBox, SIGNAL(accepted()), this, SLOT(submitForm()));
}

CreateBlockForm::~CreateBlockForm()
{
    delete ui;
}

void CreateBlockForm::submitForm()
{
    std::cout << "Submitted form" << std::endl;
    QString emisor = ui->emisorTextEdit->toPlainText();
    QString receptor = ui->receptorTextEdit->toPlainText();
    QDateTime fecha = ui->fechaTimeEdit->dateTime();

    std::string emisorStd = emisor.toStdString();
    std::string receptorStd = receptor.toStdString();
    time_t fechaUnix = fecha.toSecsSinceEpoch();
    double monto = ui->montoSpinBox->value();

    auto *block = bc->insertEntry(new TransactionEntry(emisorStd, receptorStd, monto, fechaUnix));
//    std::cout << *bc << std::endl;
    emit updatedBlockChain(block);
}
