/**
 * \file voc_utils.h
 * \brief
 *
 * \author Andrew Price
 * \date 12 2, 2013
 *
 * \copyright
 *
 * Copyright (c) 2013, Georgia Tech Research Corporation
 * All rights reserved.
 *
 * Humanoid Robotics Lab Georgia Institute of Technology
 * Director: Mike Stilman http://www.golems.org
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

#ifndef VOC_UTILS_H
#define VOC_UTILS_H

#include <string>
#include <vector>
#include <map>

#include <opencv2/core/core.hpp>
#include <opencv2/features2d/features2d.hpp>

#include "TrainingSetLoader.h"

class VOCFileStructure
{
public:
	VOCFileStructure()
	{
		baseDir = "/media/HOME/VOCdevkit/VOC2012/";
		imgDirRel = "JPEGImages/";
		setDirRel = "ImageSets/Main/";
		maskDirRel = "SegmentationObject/";
	}

	std::string baseDir;
	std::string imgDirRel;
	std::string setDirRel;
	std::string maskDirRel;

	std::string imgDir() const { return baseDir + imgDirRel; }
	std::string setDir() const { return baseDir + setDirRel; }
	std::string maskDir() const { return baseDir + maskDirRel; }
};

extern const VOCFileStructure VOC_FILE_STRUCTURE;

void getMemberList(const std::string& filename, std::vector<std::string>& files, int numToRead = -1);

void readVOCLists(const std::string directory, TrainingSet& collections, int numToRead = -1);

cv::Mat getMask(const std::string filename, int dilationRadius = 3);

void validateKeypoints(std::vector<cv::KeyPoint>& kps, const cv::Mat& mask);

#endif // VOC_UTILS_H
