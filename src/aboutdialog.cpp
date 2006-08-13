/*
 * This file is a part of QComicBook.
 *
 * Copyright (C) 2005-2006 Pawel Stolowski <yogin@linux.bydg.org>
 *
 * QComicBook is free software; you can redestribute it and/or modify it
 * under terms of GNU General Public License by Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY. See GPL for more details.
 */

#include "aboutdialog.h"
#include <qlayout.h>
#include <qlabel.h>
#include <qframe.h>
#include <qpushbutton.h>
#include <qsizepolicy.h>
#include <qpixmap.h>

using namespace QComicBook;

AboutDialog::AboutDialog(QWidget *parent, const QString &caption, const QString &text, const QPixmap &logo): QDialog(parent)
{
        setCaption(caption);
        setModal(true);
        setMinimumSize(320, 200);

        QVBoxLayout *box1 = new QVBoxLayout(this, 5, 5);
        box1->setResizeMode(QLayout::FreeResize);
        about_text = new QLabel(text, this);
        about_text->setFrameStyle(QFrame::Panel | QFrame::Sunken);
        about_text->setAlignment(Qt::AlignTop | Qt::AlignHCenter);
        about_text->setMargin(5);
        box1->addWidget(about_text);
	if (!logo.isNull())
	{
		about_logo = new QLabel(this);
		about_logo->setPixmap(logo);
		about_logo->setAlignment(Qt::AlignCenter);
		box1->addWidget(about_logo);
	}

        QPushButton *bclose = new QPushButton(tr("Close"), this);
        bclose->setDefault(true);
        bclose->setSizePolicy(QSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed));
        box1->addWidget(bclose, 0, Qt::AlignHCenter);
        connect(bclose, SIGNAL(clicked()), this, SLOT(accept()));
}

AboutDialog::~AboutDialog()
{
}

void AboutDialog::setText(const QString &text)
{
        about_text->setText(text);
}

