# PCL-filter-and-smooth

Making use of Package Point Cloud Library with existing tutorial codes to make an executable that allows user to choose their PCD file to do these actions:
1. remove outlier using StatisticalOutlierRemoval filter
2. surface reconstruction using Moving Least Squares (MLS) surface reconstruction
3. export as ply file

Precondition:

Point Cloud Library Package Installed
  - sudo apt install libpcl-dev

Instruction to run:
./filter_and_smoothing input.pcd output.ply

References:
https://pcl.readthedocs.io/projects/tutorials/en/master/resampling.html#moving-least-squares
https://pcl.readthedocs.io/projects/tutorials/en/master/statistical_outlier.html#statistical-outlier-removal
