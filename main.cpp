#include <igl/opengl/glfw/Viewer.h>
#include <igl/triangle/triangulate.h>

int main(int argc, char *argv[])
{
  // Inline mesh of a cube
  Eigen::MatrixXd V= (Eigen::MatrixXd(4,2)<<
    0.0,0.0,
    0.0,1.0,
    1.0,1.0,
    1.0,0.0).finished();
  const Eigen::MatrixXi E = (Eigen::MatrixXi(4,2)<<
    0,1,
    1,2,
    2,3,
    3,0).finished();

  Eigen::MatrixXi F;
  igl::triangle::triangulate(Eigen::MatrixXd(V),E,Eigen::MatrixXd(),"p",V,F);
  V.conservativeResize(V.rows(),3);
  V.col(2).setZero();

  // Plot the mesh
  igl::opengl::glfw::Viewer viewer;
  viewer.data().set_mesh(V, F);
  viewer.data().set_face_based(true);
  viewer.launch();
}
