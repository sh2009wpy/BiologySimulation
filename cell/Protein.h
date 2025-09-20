#ifndef AminoAcid

const int aaVariety=3;
enum AminoAcid{
	ala, //Alanine    CH3-CH(NH2)-COOH
	arg, //Arginine   HN=C(NH2)-NH-(CH2)3-CH(NH2)-COOH
	asn  //Asparagine H2N-CO-CH2-CH(NH2)-COOH
};

#endif

#ifndef maxPeptideChain
const int maxPeptideChain = 114514;
#endif


#ifndef Protein

struct Peptide{
	AminoAcid* aalist;
	int length;
	Peptide(int* aal,int l){
		length=l;
		aalist=new AminoAcid[l];
		for(int i=0;i<l;i++){
			aalist[i]=(AminoAcid)aal[i]%aaVariety;
		}
	}
	~Peptide(){
		delete aalist;
	}
};

class Protein : public Peptide{
public:
	using Peptide::Peptide;
	string name;
	Protein(int* aal,int l,string original_name=""): Peptide(aal,l){
		name=original_name;
	}
}; 

#endif 

#ifndef Enzyme

class Enzyme{
public:
	template <class Z,typename R>
	virtual R process(Z zymolyte){
		R res;
		return res;
	}
};


#endif
