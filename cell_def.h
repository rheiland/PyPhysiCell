
class Phenotype
{
    private:
    public:
        int foo;

    Phenotype();
};

class Cell_Parameters
{
 private:
 public:
	// oxygen values (in mmHg) for critical phenotype changes
	double o2_hypoxic_threshold; // value at which hypoxic signaling starts
	double o2_hypoxic_response; // value at which omics changes are observed 
	double o2_hypoxic_saturation; // value at which hypoxic signalign saturates 
	// o2_hypoxic_saturation < o2_hypoxic_threshold
	
	double o2_proliferation_saturation; // value at which extra o2 does not increase proliferation
	double o2_proliferation_threshold; // value at which o2 is sufficient for proliferation

	double o2_reference; // physioxic reference value, in the linked reference Phenotype
	// o2_proliferation_threshold < o2_reference < o2_proliferation_saturation; 
	
	double o2_necrosis_threshold; // value at which cells start experiencing necrotic death 
	double o2_necrosis_max; // value at which necrosis reaches its maximum rate 
	// o2_necrosis_max < o2_necrosis_threshold
	
	Phenotype* pReference_live_phenotype; // reference live phenotype (typically physioxic) 
	// Phenotype* pReference_necrotic_phenotype; // reference live phenotype (typically physioxic) 

	// necrosis parameters (may evenually be moved into a reference necrotic phenotype 
	double max_necrosis_rate; // deprecate
	int necrosis_type; // deprecate 
	
	Cell_Parameters(); 
}; 

class Cell_Definition
{
 private:
 public: 
	int type; 
	std::string name; 
 
	// Microenvironment* pMicroenvironment; 
	
	Cell_Parameters parameters; 
	// Custom_Cell_Data custom_data; 
	// Cell_Functions functions; 
	Phenotype phenotype; 

	Cell_Definition();  // done 
	// Cell_Definition( Cell_Definition& cd ); // copy constructor 
	// Cell_Definition& operator=( const Cell_Definition& cd ); // copy assignment 
};