/*
(c) 2009,2010,2011 Ian Clark

This file is part of Yasst.

Yasst is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

Yasst is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with Yasst.  If not, see <http://www.gnu.org/licenses/>.

*/
/* $Id: AutocompleteUserlistWidget.cpp,v 1.1 2010/04/25 23:20:27 ian Exp $

 File       : AutocompleteUserlistWidget.cpp
 Create date: 13:24:01 25 Apr 2010
 Project    : yasst

 (c) 2010 Ian Clark

*/

// Header
#include "AutocompleteUserlistWidget.h"

AutocompleteUserlistWidget::AutocompleteUserlistWidget(BirdBox *b,QWidget *text,QWidget *parent) : AutocompleteWidget(b,text,parent) {
	type=1;
	populateList();
}

AutocompleteUserlistWidget::~AutocompleteUserlistWidget() {
}

void AutocompleteUserlistWidget::populateList() {
	QList<TweetUser *> users = tweets->getUsers();
	list->clear();
	for (int x=0;x<users.size();x++) {
		TweetUser *u = users.at(x);
		if (u->screen_name.startsWith(search,Qt::CaseInsensitive))
			list->addItem(u->screen_name);
	}
}
