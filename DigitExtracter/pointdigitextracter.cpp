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
#include "pointdigitextracter.h"
#include <opencv2/opencv.hpp>
#include <iostream>

PointDigitExtracter::PointDigitExtracter()
{
}

vector<float> PointDigitExtracter::extract(Mat &src, bool do_normalize) {
    float startY, startX, square_size;
    pre_extract(src, do_normalize, startX, startY, square_size);

    for(int i = 0; i < 25; i++) {
        rectangle(src, Rect(startX, startY, square_size, square_size), Scalar(150));
        startY = floor(startY + square_size);
    }
    vector<float> results;
    return results;
}
