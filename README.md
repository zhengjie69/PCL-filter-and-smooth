# PCL-filter-and-smooth

Making use of Package Point Cloud Library with existing tutorial codes to make an executable.
<br>

<h2>Allows user to choose their PCD file to do these actions:</h2>
1. remove outlier using StatisticalOutlierRemoval filter <br />
2. surface reconstruction using Moving Least Squares (MLS) surface reconstruction <br />
3. export as ply or pcd file <br />



<h2>Precondition:</h2>

Point Cloud Library Package Installed
  - sudo apt install libpcl-dev



<h2>Instruction to run:</h2>
  - cmake . <br />
  - make <br/>


<h3>For exportation to ply:</h3><br />
./filter_and_smoothing_ply input.pcd output.ply
<br />
<h3>For exportation to pcd:</h3><br />
./filter_and_smoothing_pcd input.pcd output.pcd



<h2>References:</h2>

https://pcl.readthedocs.io/projects/tutorials/en/master/resampling.html#moving-least-squares
https://pcl.readthedocs.io/projects/tutorials/en/master/statistical_outlier.html#statistical-outlier-removal
