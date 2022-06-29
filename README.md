# PCL-filter-and-smooth

<h2>Making use of Package Point Cloud Library with existing tutorial codes to make an executable.</h2>


<h2>Allows user to choose their PCD file to do these actions:</h2>
1. remove outlier using StatisticalOutlierRemoval filter
2. surface reconstruction using Moving Least Squares (MLS) surface reconstruction
3. export as ply file



<h2>Precondition:</h2>

Point Cloud Library Package Installed
  - sudo apt install libpcl-dev



<h2>Instruction to run:</h2>
./filter_and_smoothing input.pcd output.ply



<h2>References:</h2>

https://pcl.readthedocs.io/projects/tutorials/en/master/resampling.html#moving-least-squares
https://pcl.readthedocs.io/projects/tutorials/en/master/statistical_outlier.html#statistical-outlier-removal
