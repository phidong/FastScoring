/****************************************************************************
**FastScoring is a program developed entirely based on open source that help
**school staff entering points faster and easier.
**    Copyright (C) 2013  OPEN-VN.ORG Team
**
**    This program is free software: you can redistribute it and/or modify
**    it under the terms of the GNU Affero General Public License as published by
**    the Free Software Foundation, either version 3 of the License, or
**    (at your option) any later version.
**
**    This program is distributed in the hope that it will be useful,
**    but WITHOUT ANY WARRANTY; without even the implied warranty of
**    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
**    GNU Affero General Public License for more details.
**
**    You should have received a copy of the GNU Affero General Public License
**    along with this program.  If not, see <http://www.gnu.org/licenses/>.
****************************************************************************/

#include "courseinfowidget.h"
#include "globalsetting.h"
#include "ui_courseinfowidget.h"
#include <QDebug>

CourseInfoWidget::CourseInfoWidget(QWidget *parent) :
    QTabWidget(parent),
    ui(new Ui::CourseInfoWidget)
{
    ui->setupUi(this);
    ui->tableView->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tableView->setSelectionMode(QAbstractItemView::SingleSelection);
    fprinter = new FormPrinter(GlobalSetting::steps());
//    connect(this, &MainWindow::PrintClicked,
//            fprinter, &FormPrinter::Print);

    connect(ui->btPrint, &QPushButton::clicked,
            this, &CourseInfoWidget::Print);
}

void CourseInfoWidget::LoadCourseList() {
    emit GetCourseList("2013", "2", "id-f-123", "id-s-456", "id-l-789", NULL);
}

void CourseInfoWidget::DisplayCourseList(CourseSummaryList *sumary, Response r) {
    ui->tableView->setModel(sumary);
}

CourseInfoWidget::~CourseInfoWidget()
{
    delete ui;
}

void CourseInfoWidget::Print() {
    CourseInfo inf;
    qDebug() << "clekcekdakjdhakda";
    emit PrintClicked(&inf);
}
