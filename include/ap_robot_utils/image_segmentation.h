/**
 * \file image_segmentation.h
 * \brief
 *
 * \author Andrew Price
 * \date November 19, 2013
 *
 * \copyright
 *
 * Copyright (c) 2013, Georgia Tech Research Corporation
 * All rights reserved.
 *
 * This file is provided under the following "BSD-style" License:
 * Redistribution and use in source and binary forms, with or
 * without modification, are permitted provided that the following
 * conditions are met:
 * * Redistributions of source code must retain the above copyright
 *   notice, this list of conditions and the following disclaimer.
 * * Redistributions in binary form must reproduce the above
 *   copyright notice, this list of conditions and the following
 *   disclaimer in the documentation and/or other materials provided
 *   with the distribution.
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND
 * CONTRIBUTORS "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES,
 * INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
 * MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR
 * CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
 * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
 * LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF
 * USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED
 * AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN
 * ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 */

#ifndef IMAGESEGMENTATION_H
#define IMAGESEGMENTATION_H

#include <opencv2/core/core.hpp>

namespace ap
{

typedef std::vector<cv::Point2i> Segment;

class Segmentation
{
public:
	Segmentation(cv::Size2i size)
	{
		pixelsToSegment = cv::Mat1i(size, 0);
		edges = cv::Mat1b(size, 0);
	}

	std::vector<Segment> segmentToPixels;
	cv::Mat1i pixelsToSegment;
	cv::Mat1b edges;
};

typedef float (*DifferenceFunction)(const cv::Mat& image, int x1, int y1, int x2, int y2);

float diffSTD(const cv::Mat& image, int x1, int y1, int x2, int y2);
float diffHSV(const cv::Mat& image, int x1, int y1, int x2, int y2);

void segmentFelzenszwalb(const cv::Mat& input, Segmentation& s, const float c, unsigned int min_size, DifferenceFunction diff = &diffSTD);

void recolorSegmentation(const cv::Mat& colorIm, cv::Mat& recolorIm, const Segmentation &s, bool useAverageColor = false, bool drawEdges = true);

void getSegmentMask(const Segmentation& s, const int segmentIdx, cv::Mat& mask);

}

#endif // IMAGESEGMENTATION_H
