# PyPhysiCell

Try doing the following:
```
cd PhysiCell_1.6.0
# on Mac
make
# on Linux
cp Make-linux make
make

make bind
```

If successful, it should create `pyphysicell.cpython-38-darwin.so` (on macOS).

```
~/git/PyPhysiCell/PhysiCell_1.6.0$ python
Python 3.8.8 (default, Apr 13 2021, 12:59:45) 
[Clang 10.0.0 ] :: Anaconda, Inc. on darwin
Type "help", "copyright", "credits" or "license" for more information.
>>> import pyphysicell as pcell
>>> dir(pcell)
['Cell_Definition', 'Cell_Functions', 'Microenvironment', 'Microenvironment_Options', 'PhysiCell_Globals', 'PhysiCell_Settings', '__doc__', '__file__', '__loader__', '__name__', '__package__', '__spec__', 'create_cell_container2', 'create_cell_types', 'get_cells_pos2D', 'get_cells_types', 'get_cells_x', 'get_cells_y', 'get_instance_microenvironment', 'get_microenvironment_options', 'get_num_cells', 'get_physicell_globals', 'get_physicell_settings', 'initialize_microenvironment', 'load_PhysiCell_config_file', 'setup_tissue', 'update_all_cells']
>>> 
```

Very old gdoc and out of date:
https://docs.google.com/document/d/13kBEArUECNitFu0CGMuy-6hhNpmmVRrGp6naAAg7xr8/edit#
