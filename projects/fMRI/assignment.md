# functional MRI

## Introduction

Functional magnetic resonance imaging (fMRI) uses MRI scanning to measure brain activity by detecting changes associated with blood oxygenation. Typically, an fMRI scan involves acquisition of a sequence of time-resolved fMRI volumes. During acquisition, the subject will alternate performance of a 'task' with periods of 'rest'. For example, the task might be viewing visual stimuli or listening to audio stimuli. The aim of the scan is to discover which part(s) of the brain are active
during the task. 

Once the sequence of fMRI volumes has been acquired, it must be processed to produce an image showing which parts of the brain were active during the task. This image is known as a correlation image. Figure 1 illustrates the processing involved in producing this image. First, a task function is formed, which is a 1-D signal indicating the periods of task and rest during the scan. There will be one value in the task function for each fMRI volume. Next, for each fMRI volume voxel, a similar 1-D signal is formed consisting of the fMRI intensities from each volume in the sequence. The Pearson’s correlation coefficient between the task and fMRI 1-D signals represents the intensity of the correlation image for that voxel. The Pearson’s correlation coefficient $r$ of two signals $\\{ x_i \\}$ and $\\{ y_i \\}$ of length $N$ is defined as: 

$$r = \frac{\sum_{i=1}^{N} (x_i - \bar{x}) \times (y_i - \bar{y})}{\sqrt{\sum_{i=1}^{N} (x_i - \bar{x})^2} \times \sqrt{\sum_{i=1}^{N} (y_i - \bar{y})^2}} $$

where $\bar{x}$ and $\bar{y}$ represent the mean values of $x$ and $y$, The correlations are computed for all voxels, resulting in the full 3-D correlation image. Due to the noisy nature of the data, the correlation image is normally smoothed before visualisation. 

The figure below shows examples of a single fMRI volume and a correlation image computed from a sequence of such volumes.

---

![Illustration of function MRI](fmri.png)

*An illustration of how a sequence of fMRI volumes is correlated with a task function to produce an fMRI correlation image.*

---

## Instructions

Your task in this coursework is to write a simple program for fMRI analysis to compute correlation images from given sequences of fMRI data and the corresponding task timecourse. For simplicity, the data provided correspond to a single slice through the 3D dataset. The data themselves come from [a study on the visual system](https://openneuro.org/datasets/ds001553/versions/1.0.1), and consist of a flickering checkerboard task. The final output of the project should look like this:

---

![example output for fMRI project](terminal_output.png)

*Example output for the project, showing am example image of the original fMRI data (top) and the resulting fMRI correlation image (bottom). In these data, we see clear activation of the visual cortex, in the occipital pole at the back of the brain.*

---


### fMRI source data 

The data to be processed are stored in the [data folder](data/). To keep the project manageable, the data consists of a single slice per time point (the original data consist of full 3D images for each time point). These data are stored as a set of numbered files, one per timepoint, named `fmri-???.pgm` (where `???` is the time point number), using the [plain PGM format](https://netpbm.sourceforge.net/doc/pgm.html#plainpgm), which is a simple text-only image format. 

The task information is stored in the text file [data/task.txt](data/task.txt), consisting of 0 or 1, one per time point, indicating which time point corresponds to a rest (0) or active (1) time point. 

### Representing image information

The next challenge is to represent 2 (or more) dimensional information using standard C++ functionality. There are various ways of doing this, but some are more suitable than others. It would be tempting to use a vector of vectors (e.g. `std::vector<std::vector<int>>` or similar), but there are a number of reasons why this is not recommended. For instance, it allows different rows to have different sizes, when we know our data have fixed dimensions - this may introduce errors down the line. It also implies that each row needs to manage its own memory, which comes with a performance penalty. 

A better solution is to use a one-dimensional vector of data, large enough to contain all $N_{rows} \times N_{columns}$ pixel intensities, and provide functionality to access each pixel intensity based on its $(x,y)$ coordinates. The mapping between the pixel intensity at $(x,y)$ and its offset in the data vector is a common operation, and for 2D arrays, is often referred to as [row-major or column-major ordering](https://en.wikipedia.org/wiki/Row-_and_column-major_order). In C and C++, it is common to use row-major ordering: essentially, we store the first row of pixel intensities as the first block of values in the data vector, then store the second row immediately after that, and so on until the full image has been stored. The offset to the pixel at $(x,y)$ is then simply given as $n = x + n_x \times y$ (where $n_x$ is the number of pixels along the *x*-axis (i.e. the _width_ of the image).

Once you have functionality to access a single image slice, this can be used to access all the image slices. To help you with this, it is recommended to rely on the shell's [globbing functionality](https://www.shell-tips.com/bash/wildcards-globbing/) - specifically the `*` wildcard. 

### Inspecting the time course information

It is a good idea to have a way to inspect the values you have loaded from file, to make sure that everything matches your expectations. A simple way to do this is to simply print out the values to the terminal. If needed, you can always copy & paste these values into another software package such as Matlab or Excel to display them as a graph. However, we can also display them directly on the terminal using an ancient (~1983) protocol called [sixel encoding](https://en.wikipedia.org/wiki/Sixel) (originally designed to control dot-matrix printers!). Not all terminals support this, but the one provided to you via the MSYS2 project does (the terminal itself is called [mintty](https://mintty.github.io/)). On macOS, we recommend you install [the iTerm2 terminal](https://iterm2.com/), which also provides sixel support. Another good option if that doesn't work is [wezterm](https://wezfurlong.org/wezterm/index.html). 

To use this functionality, we will rely on the [terminal graphics project](https://github.com/jdtournier/terminal_graphics) project, which is a really simple single-file header-only library. It allows simple plots and images to be displayed on a sixel-compatible terminal. Please see the information on [that project's README](https://github.com/jdtournier/terminal_graphics/blob/main/README.md) for details, including [the documentation on how to use it](https://jdtournier.github.io/terminal_graphics/).

### Computing the correlation coefficient

Once you have a vector of intensities for a pixel of interest, and a vector of task status (rest/active), you can compute the correlation between them using the formula shown above. It's a good idea to start with a single pixel, and test that the correlation value you compute matches the value you might expect from the time course data (which you will hopefully have displayed alongside the correlation value itself!). To do this well, you will need some way to specify which pixel to display - and the most efficient way to do this is via command-line arguments (or even better, via a command-line option). 

Once you are satisfied that computation is correct on an individual pixel basis, it should be straightforward to generate a full image of the correlation coefficient for each pixel, and display that. 
