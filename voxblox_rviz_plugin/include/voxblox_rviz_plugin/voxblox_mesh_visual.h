#ifndef VOXBLOX_RVIZ_PLUGIN_VOXBLOX_MESH_VISUAL_H
#define VOXBLOX_RVIZ_PLUGIN_VOXBLOX_MESH_VISUAL_H

#include <OGRE/OgreManualObject.h>

#include <voxblox/core/block_hash.h>
#include <voxblox_msgs/Mesh.h>

namespace Ogre {
class Vector3;
class Quaternion;
class ManualObject;
}

namespace voxblox_rviz_plugin {

// Visualizes a single grid_map_msgs::GridMap message.
class VoxbloxMeshVisual {
 public:
  VoxbloxMeshVisual(Ogre::SceneManager* scene_manager,
                    Ogre::SceneNode* parent_node);
  virtual ~VoxbloxMeshVisual();

  void setMessage(const voxblox_msgs::Mesh::ConstPtr& msg);

  // Set the coordinate frame pose.
  void setFramePosition(const Ogre::Vector3& position);
  void setFrameOrientation(const Ogre::Quaternion& orientation);

 private:
  Ogre::SceneNode* frame_node_;
  Ogre::SceneManager* scene_manager_;

  voxblox::AnyIndexHashMapType<Ogre::ManualObject*>::type object_map_;
};

}  // namespace voxblox_rviz_plugin

#endif  // VOXBLOX_RVIZ_PLUGIN_VOXBLOX_MESH_VISUAL_H
