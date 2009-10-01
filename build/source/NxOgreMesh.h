/** 
    
    This file is part of NxOgre.
    
    Copyright (c) 2009 Robin Southern, http://www.nxogre.org
    
    Permission is hereby granted, free of charge, to any person obtaining a copy
    of this software and associated documentation files (the "Software"), to deal
    in the Software without restriction, including without limitation the rights
    to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
    copies of the Software, and to permit persons to whom the Software is
    furnished to do so, subject to the following conditions:
    
    The above copyright notice and this permission notice shall be included in
    all copies or substantial portions of the Software.
    
    THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
    IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
    FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
    AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
    LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
    OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
    THE SOFTWARE.
    
*/

                                                                                       

#ifndef NXOGRE_MESH_H
#define NXOGRE_MESH_H

                                                                                       

#include "NxOgreStable.h"
#include "NxOgreCommon.h"
#include "NxOgreMeshStats.h"

                                                                                       

namespace NxOgre
{

                                                                                       

/** \brief
*/
class NxOgrePublicClass Mesh
{
  
  public: // Functions
  
  friend class MeshManager;
  template<class T> friend inline void ::NxOgre::Functions::safe_delete(T*);
  
  /** \brief Set the name of this Mesh
  */
  void                                        setName(const char*);
  
  /** \brief Set the name of this Mesh
  */
  void                                        setName(const String&);
  
  /** \brief Get the name of this mesh.
  */
  String                                      getName() const;
  
  /** \brief Get the name of this mesh.
  */
  StringHash                                  getNameHash() const;
  
  /** \brief Text
  */
  Enums::MeshType                             getType(void) const;
  
  /** \brief Is the shape loaded?
  */
  bool                                        isLoaded(void) const;
  
  /** \brief Is a shape(s) using this mesh?
  */
  bool                                        isUsed(void) const;
  
  /** \brief Load a mesh from a resource, and take on that mesh.
  */
  void                                        load(Resource*);
  
  /** \brief Unload the mesh.
  */
  void                                        unload();

  /** \brief Get's the convex mesh, or null
  */
  NxConvexMesh*                               getAsConvex();
  
  /** \brief Get's the convex mesh, or null
  */
  NxTriangleMesh*                             getAsTriangleMesh();
  
  /** \brief Get's the convex mesh, or null
  */
  NxClothMesh*                                getAsCloth();
  
  /** \brief Get's the soft body mesh, or null
  */
  NxSoftBodyMesh*                             getAsSoftBody();

  /** \brief Get's the soft body mesh, or null
  */
  SoftBodyMesh*                               getAsSoftBodyMesh();

  /** \brief Get's the convex mesh, or null
  */
  NxCCDSkeleton*                              getAsSkeleton();

  /** \brief Get and/or calculate the statistics of the mesh
  */
  MeshStats                                   getStats();
  
  /** \brief Get the texture coords.
  */
  Buffer<float>&                              getTextureCoords();

  /** \brief Save the mesh information into MeshData
      \note  You should NxOgre_Delete the MeshData pointer after use.
  */
  MeshData*                                   getMeshData();
  
  protected: // Variables
  
  Enums::MeshType                             mType;
 
  union
  {
   NxConvexMesh*                              mConvex;
   NxTriangleMesh*                            mTriangle;
   NxClothMesh*                               mCloth;
   NxSoftBodyMesh*                            mSoftBody;
   NxCCDSkeleton*                             mSkeleton;
  } mMesh;
  
  /** \brief Render vertices
  */
  Buffer<float>                               mVertices;

  /** \brief Render indices
  */
  Buffer<unsigned int>                        mIndices;

  /** \brief Render normals
  */
  Buffer<float>                               mNormals;
  
  /** \brief Render texture coords
  */
  Buffer<float>                               mTextureCoords;
  
  /** \brief Name of the mesh
  */
  String                                      mName;
  
  /** \brief Hash of the name of the mesh.
  */
  StringHash                                  mNameHash;

  /** \brief
  */
  MeshStats                                   mMeshStats;
  
  protected:
  
  /** \brief Mesh constructor
  */
                                              Mesh();
  
  /** \brief Mesh constructor, equilvent of calling load(uri);
  */
                                              Mesh(Resource*);
  
  /** \brief Text
  */
                                             ~Mesh(void);
  
}; // class Mesh

                                                                                       

} // namespace NxOgre

                                                                                       

#endif
