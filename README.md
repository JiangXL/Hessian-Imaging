# Hessian-Imaging
Image Process of Hessian Imaging Microscope 

For better flexibity and less cross-taking, we attempt to use Hessian Imaging,
which uses deconvolution algorithm based on Hessian matrixes for fluorescence
images with very short exposure instead of normal exposure.

More can reference to this article.(Huang et al., 2018)

# Usage
dependence
`opencv`(test on 3.4), `cmake` ,`gcc`

build
```bash
cd Hessian-Imaging
cmake ./
make
```

run
```bash
./hessian <raw-image-foler> <output-folder>
```

