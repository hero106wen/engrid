//
// ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// +                                                                      +
// + This file is part of enGrid.                                         +
// +                                                                      +
// + Copyright 2008,2009 Oliver Gloth                                     +
// +                                                                      +
// + enGrid is free software: you can redistribute it and/or modify       +
// + it under the terms of the GNU General Public License as published by +
// + the Free Software Foundation, either version 3 of the License, or    +
// + (at your option) any later version.                                  +
// +                                                                      +
// + enGrid is distributed in the hope that it will be useful,            +
// + but WITHOUT ANY WARRANTY; without even the implied warranty of       +
// + MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the        +
// + GNU General Public License for more details.                         +
// +                                                                      +
// + You should have received a copy of the GNU General Public License    +
// + along with enGrid. If not, see <http://www.gnu.org/licenses/>.       +
// +                                                                      +
// ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//

#include "smoothandswapsurface.h"

SmoothAndSwapSurface::SmoothAndSwapSurface()
{
  EG_TYPENAME;
  m_PerformGeometricTests = true;
  m_UseProjectionForSmoothing = false;
  m_UseNormalCorrectionForSmoothing = false;
  m_FeatureAngle = GeometryTools::deg2rad(30);
  m_AllowFeatureEdgeSwapping = false;
}

void SmoothAndSwapSurface::operate()
{
  prepare();
  cout << "1st Delaunay swap" << endl;
  swap();
  cout << "smoothing" << endl;
  smooth(0);
  cout << "2nd Delaunay swap" << endl;
  //swap();
  createIndices(grid);
  updateNodeInfo(false);
  computeMeshDensity();
}
