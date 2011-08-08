#include <QtGui>

extern "C" {
	#include "mean.h"
}

#include "finddialog.h"


FindDialog::FindDialog(QWidget *parent)
     : QDialog(parent)
{
    label = new QLabel(tr("Find &what:"));
    lineEdit = new QLineEdit;
    label->setBuddy(lineEdit);

    caseCheckBox = new QCheckBox(tr("Match &case"));
    backwardCheckBox = new QCheckBox(tr("Search &backward"));

    findButton = new QPushButton(tr("&Find"));
    findButton->setDefault(true);
    findButton->setEnabled(false);


    closeButton = new QPushButton(tr("Close"));
   
    connect(lineEdit, SIGNAL(textChanged(const QString &)),
           this, SLOT(enableFindButton(const QString &)));
   connect(findButton, SIGNAL(clicked()),
           this, SLOT(findClicked()));
   connect(closeButton, SIGNAL(clicked()),
           this, SLOT(close()));

    QHBoxLayout *topLeftLayout = new QHBoxLayout;
    topLeftLayout->addWidget(label);
    topLeftLayout->addWidget(lineEdit);

    QVBoxLayout *leftLayout = new QVBoxLayout;
    leftLayout->addLayout(topLeftLayout);
    leftLayout->addWidget(caseCheckBox);
    leftLayout->addWidget(backwardCheckBox);

    QVBoxLayout *rightLayout = new QVBoxLayout;
    rightLayout->addWidget(findButton);
    rightLayout->addWidget(closeButton);
    rightLayout->addStretch();

    QHBoxLayout *mainLayout = new QHBoxLayout;
    mainLayout->addLayout(leftLayout);
    mainLayout->addLayout(rightLayout);
    setLayout(mainLayout);
    setWindowTitle(tr("Find"));
    setFixedHeight(sizeHint().height());
}

void FindDialog::enableFindButton(const QString &text)
{
    findButton->setEnabled(!text.isEmpty());
}

void FindDialog::findClicked()
{
    QLabel *label = new QLabel(tr("not found. <br />But I've a number for you: %1").arg( mean(5,8) ));
    label->show();
}

