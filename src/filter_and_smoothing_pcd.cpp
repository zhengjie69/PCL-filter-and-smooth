#include <pcl/point_types.h>
#include <pcl/io/pcd_io.h>
#include <pcl/io/ply_io.h>
#include <pcl/search/kdtree.h>
#include <pcl/surface/mls.h>
#include <pcl/filters/statistical_outlier_removal.h>
#include <pcl/console/parse.h>

using namespace pcl;
using namespace pcl::io;
using namespace pcl::console;

void printHelp (int, char **argv)
{
  print_error ("Syntax is: %s input.pcd output.pcd\n", argv[0]);
}

int main (int argc, char** argv)
{

  print_info ("Clean out outliers in point cloud data and execute surface reconstruction on a PCD file, then export the file in PCD format. For more information, use: %s -h\n", argv[0]);

  if (argc < 3)
  {
    printHelp (argc, argv);
    return (-1);
  }

  std::vector<int> pcd_file_indices = parse_file_extension_argument (argc, argv, ".pcd");

  if (pcd_file_indices.size () != 2)
  {
    print_error ("Need one input PCD file and one output PCD filename.\n");
    return (-1);
  }

  // Load input file into a PointCloud<T> with an appropriate type
  pcl::PointCloud<pcl::PointXYZRGB>::Ptr cloud (new pcl::PointCloud<pcl::PointXYZRGB> ());
  pcl::PointCloud<pcl::PointXYZRGB>::Ptr cloud_filtered (new pcl::PointCloud<pcl::PointXYZRGB>);
  // Load bun0.pcd -- should be available with the PCL archive in test 
  pcl::io::loadPCDFile (argv[pcd_file_indices[0]], *cloud);

  // Create the filtering object
  pcl::StatisticalOutlierRemoval<pcl::PointXYZRGB> sor;
  sor.setInputCloud (cloud);
  sor.setMeanK (50);
  sor.setStddevMulThresh (1.0);
  sor.filter (*cloud_filtered);

  // Create a KD-Tree
  pcl::search::KdTree<pcl::PointXYZRGB>::Ptr tree (new pcl::search::KdTree<pcl::PointXYZRGB>);

  // Output has the PointNormal type in order to store the normals calculated by MLS
  // pcl::PointCloud<pcl::PointNormal> mls_points;
  pcl::PointCloud<pcl::PointXYZRGB> mls_points;

  // Init object (second point type is for the normals, even if unused)
  // pcl::MovingLeastSquares<pcl::PointXYZRGB, pcl::PointNormal> mls;
  pcl::MovingLeastSquares<pcl::PointXYZRGB, pcl::PointXYZRGB> mls;
 
  mls.setComputeNormals (true);

  // Set parameters
  mls.setInputCloud (cloud_filtered);
  mls.setPolynomialOrder (2);
  mls.setSearchMethod (tree);
  mls.setSearchRadius (0.03);

  // Reconstruct
  mls.process (mls_points);

  // Save output as PCD
  pcl::io::savePCDFile (argv[pcd_file_indices[1]], mls_points);
  
}