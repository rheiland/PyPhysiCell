from pyphysicell import *
#retval = load_PhysiCell_config_file("config/Physicell_settings.xml")
retval = load_PhysiCell_config_file("config/cancerbots.xml")
initialize_microenvironment()                                                                                  
menv = get_microenvironment()
print('menv.decay_rates=',menv.decay_rates)
menv_opt = get_microenvironment_options()
print('menv_opt.simulate_2D=',menv_opt.simulate_2D)