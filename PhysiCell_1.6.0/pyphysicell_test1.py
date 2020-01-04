
from pyphysicell import *

retval = load_PhysiCell_config_file("biorobots.xml")
initialize_microenvironment()
menv = get_instance_microenvironment()
print('menv.decay_rates=',menv.decay_rates)
mechanics_voxel_size = 30
create_cell_container2( mechanics_voxel_size )
create_cell_types()
setup_tissue()
settings = get_physicell_settings()
print('settings.max_time=',settings.max_time)
pc_globals = get_physicell_globals()
diffusion_dt, mechanics_dt, phenotype_dt = 0.01, 0.1, 6.0
max_steps = int(settings.max_time / diffusion_dt)
for istep in range(0, max_steps):
    menv.simulate_diffusion_decay( diffusion_dt )
    update_all_cells(pc_globals.current_time)
    if (istep % 10000) == 0:
        print(pc_globals.current_time,') # cells= ',get_num_cells())
    pc_globals.current_time += diffusion_dt

