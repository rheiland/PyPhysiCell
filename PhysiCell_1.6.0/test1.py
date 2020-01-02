import numpy as np
from pyphysicell import *
import faulthandler

faulthandler.enable()

# --- TODO! Delete model, e.g. all_cells->size()  --> 0

retval = load_PhysiCell_config_file("config/Physicell_settings.xml")
# retval = load_PhysiCell_config_file("config/cancerbots.xml")
initialize_microenvironment()   # in setup_microenvironment()
menv = get_instance_microenvironment()
print('menv.decay_rates=',menv.decay_rates)
menv_opt = get_microenvironment_options()
print('menv_opt.simulate_2D=',menv_opt.simulate_2D)

# double mechanics_voxel_size = 30; 
# this creates  std::vector<Cell*> *all_cells;
mechanics_voxel_size = 30
# --- original method took pointer to menv!
# Cell_Container* create_cell_container_for_microenvironment( BioFVM::Microenvironment& m , double mechanics_voxel_size )
# --- 
# Cell_Container* cell_container = create_cell_container_for_microenvironment( microenvironment, mechanics_voxel_size );
#create_cell_container_for_microenvironment( menv, mechanics_voxel_size )
create_cell_container2( mechanics_voxel_size )

create_cell_types()
# setup_tissue1()
setup_tissue()

settings = get_physicell_settings()
print('settings.omp_num_threads=',settings.omp_num_threads)
print('settings.max_time=',settings.max_time)

pc_globals = get_physicell_globals()

# rf. PhysiCell_constants.h
diffusion_dt = 0.01
mechanics_dt = 0.1
phenotype_dt = 6.0

#tdel = settings.max_time/4.0

# display_citations(); 
## set the performance timers 
# BioFVM::RUNTIME_TIC();
# BioFVM::TIC();

# for mytime in np.arange(0, settings.max_time, tdel):
max_steps = settings.max_time / diffusion_dt
for istep in range(0, 10):
    # print('time (for loop)=',mytime)
    print('current_time=',pc_globals.current_time)

    # update the microenvironment
	# microenvironment.simulate_diffusion_decay( diffusion_dt );
    menv.simulate_diffusion_decay( diffusion_dt )

	# run PhysiCell 
	# ((Cell_Container *)microenvironment.agent_container)->update_all_cells( PhysiCell_globals.current_time );
#void Cell_Container::update_all_cells(double t)
#{
#	update_all_cells(t, phenotype_dt, mechanics_dt , diffusion_dt );
    # update_all_cells(mytime)
    update_all_cells(pc_globals.current_time)
    print('# cells= ',get_num_cells())
			
	# PhysiCell_globals.current_time += diffusion_dt
    pc_globals.current_time += diffusion_dt

pos = get_cells_pos2D()
a = np.asarray(pos)  # len(a)
