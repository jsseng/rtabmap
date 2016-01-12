/*
Copyright (c) 2010-2014, Mathieu Labbe - IntRoLab - Universite de Sherbrooke
All rights reserved.

Redistribution and use in source and binary forms, with or without
modification, are permitted provided that the following conditions are met:
    * Redistributions of source code must retain the above copyright
      notice, this list of conditions and the following disclaimer.
    * Redistributions in binary form must reproduce the above copyright
      notice, this list of conditions and the following disclaimer in the
      documentation and/or other materials provided with the distribution.
    * Neither the name of the Universite de Sherbrooke nor the
      names of its contributors may be used to endorse or promote products
      derived from this software without specific prior written permission.

THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY
DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
(INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
(INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*/

#ifndef REGISTRATIONVIS_H_
#define REGISTRATIONVIS_H_

#include "rtabmap/core/RtabmapExp.h" // DLL export/import defines

#include <rtabmap/core/Registration.h>
#include <rtabmap/core/Signature.h>

namespace rtabmap {

// Visual registration
class RTABMAP_EXP RegistrationVis : public Registration
{
public:
	// take ownership of child
	RegistrationVis(const ParametersMap & parameters = ParametersMap(), Registration * child = 0);
	virtual ~RegistrationVis();

	virtual void parseParameters(const ParametersMap & parameters);

	float getInlierDistance() const {return _inlierDistance;}
	int getIterations() const {return _iterations;}
	int getMinInliers() const {return _minInliers;}

protected:
	virtual Transform computeTransformationImpl(
			Signature & from,
			Signature & to,
			Transform guess,
			RegistrationInfo & info) const;

	virtual bool isImageRequiredImpl() const {return true;}
	virtual int getMinVisualCorrespondencesImpl() const {return _minInliers;}

private:
	int _minInliers;
	float _inlierDistance;
	int _iterations;
	int _refineIterations;
	float _epipolarGeometryVar;
	int _estimationType;
	bool _forwardEstimateOnly;
	float _PnPReprojError;
	int _PnPFlags;
	int _PnPRefineIterations;
	int _correspondencesApproach;
	int _flowWinSize;
	int _flowIterations;
	float _flowEps;
	int _flowMaxLevel;

	ParametersMap _featureParameters;
};

}

#endif /* REGISTRATION_H_ */