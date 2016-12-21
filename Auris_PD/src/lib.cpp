using namespace std;

int manipulation_filters::filter_lowpass_pre(string p, string pSave)
{
  string frequency = "250"; //Hz, low pass
  string gain_     = "2"; //~db
  char * au_files = getenv("AURIS_FILES");
  if(au_files == NULL)
  {
    clog << "Erro com a variavel AURIS_FILES nao setada, abortando.\n";
    exit(-1);
  }
  char *path = (char *)malloc(100);
  char *pathSave = (char *)malloc(100);
  strcat(path, au_files);
  strcat(path, p.c_str());
  strcat(pathSave, au_files);
  strcat(pathSave, pSave.c_str());
  command  *obj_exec      = new command();
  string sup_r = "0.7", sup_l = "0.7";
  string c = "pd  -open \"" + loc_patch +"\" -send \"local "+ path +"\" -send \"pd dsp 1\" -send \"controlLopl 1\" -send \"controlLopr 1\" -send \"flopl "  + frequency + "\" -send \" flopr " + frequency + "\" -send \"controlHipl 1\" -send \"controlHipr 1\" -send \"fhipl " + frequency + "\" -send \"fhipr " + frequency + "\" -send \" ganhoLopr " + gain_ + "\" -send \" ganhoLopl " + gain_ + "\" -send \"save "+ pathSave +"\" -send \" ganhoHipl " + sup_l +" \" -send \" ganhoHipr " + sup_r +" \"";
  //cout << c << endl;
  return obj_exec -> do_command(c);
}

int manipulation_filters::filter_lowpass(string p, string frequency_input, string gain_input, string suppress_high_freq_l, string suppress_high_freq_r, string pSave)
{
  //clog << path<<" "<<frequency_input<<" "<<gain_input<<" "<<suppress_high_freq_l <<" "<< suppress_high_freq_r;
  char * au_files = getenv("AURIS_FILES");
  if(au_files == NULL)
  {
    clog << "Erro com a variavel AURIS_FILES nao setada, abortando.\n";
    exit(-1);
  }
  char *path = (char *)malloc(100);
  char *pathSave = (char *)malloc(100);
  strcat(path, au_files);
  strcat(path, p.c_str());
  strcat(pathSave, au_files);
  strcat(pathSave, pSave.c_str());
  string frequency = frequency_input; //Hz, low pass
  string gain_     = gain_input; //~db
  command  *obj_exec      = new command();
  string sup_l = suppress_high_freq_l;
  string sup_r = suppress_high_freq_r;
  string c = "pd -open \"" + loc_patch +"\" -send \"local " + path + "\" -send \"pd dsp 1\" -send \"controlLopl 1\" -send \"controlLopr 1\" -send \"flopl "  + frequency + "\" -send \" flopr " + frequency + "\" -send \"controlHipl 1\" -send \"controlHipr 1\" -send \"fhipl " + frequency + "\" -send \"fhipr " + frequency + "\" -send \" ganhoLopr " + gain_ + "\" -send \" ganhoLopl " + gain_ + "\" -send \"save "+ pathSave +"\" -send \" ganhoHipl " + sup_l +" \" -send \" ganhoHipr " + sup_r +" \"";
  //cout << c << endl;
  return obj_exec -> do_command(c);
}

int manipulation_filters::filter_highpass_pre(string p, string pSave)
{
  char * au_files = getenv("AURIS_FILES");
  if(au_files == NULL)
  {
    clog << "Erro com a variavel AURIS_FILES nao setada, abortando.\n";
    exit(-1);
  }
  char *path = (char *)malloc(100);
  char *pathSave = (char *)malloc(100);
  strcat(path, au_files);
  strcat(path, p.c_str());
  strcat(pathSave, au_files);
  strcat(pathSave, pSave.c_str());
  string frequency = "11000"; //Hz, low pass
  string gain_     = "2"; //~db
  command  *obj_exec      = new command();
  string sup_r = "0.7", sup_l = "0.7";
  string c = "pd  -open \"" + loc_patch +"\" -send \"local " + path +"\" -send \"pd dsp 1\" -send \"controlLopl 1\" -send \"controlLopr 1\" -send \"flopl "  + frequency + "\" -send \" flopr " + frequency + "\" -send \"controlHipl 1\" -send \"controlHipr 1\" -send \"fhipl " + frequency + "\" -send \"fhipr " + frequency + "\" -send \" ganhoHipr " + gain_ + "\" -send \" ganhoHipl " + gain_ + "\" -send \"save "+ pathSave +"\" -send \" ganhoLopl " + sup_l +" \" -send \" ganhoLopr " + sup_r +" \"";
  //cout << c << endl;
  return obj_exec -> do_command(c);
}

int manipulation_filters::filter_highpass(string p, string frequency_input, string gain_input, string suppress_low_freq_l, string suppress_low_freq_r, string pSave)
{
  char * au_files = getenv("AURIS_FILES");
  if(au_files == NULL)
  {
    clog << "Erro com a variavel AURIS_FILES nao setada, abortando.\n";
    exit(-1);
  }
  char *path = (char *)malloc(100);
  char *pathSave = (char *)malloc(100);
  strcat(path, au_files);
  strcat(path, p.c_str());
  string frequency = frequency_input; //Hz, low pass
  string gain_     = gain_input; //~db
  command  *obj_exec      = new command();
  string sup_l = suppress_low_freq_l;
  string sup_r = suppress_low_freq_r;
  strcat(pathSave, au_files);
  strcat(pathSave, pSave.c_str());
  string c = "pd -open \"" + loc_patch +"\" -send \"local " + path +"\"  -send \"pd dsp 1\" -send \"controlLopl 1\" -send \"controlLopr 1\" -send \"flopl "  + frequency + "\" -send \" flopr " + frequency + "\" -send \"controlHipl 1\" -send \"controlHipr 1\" -send \"fhipl " + frequency + "\" -send \"fhipr " + frequency + "\" -send \" ganhoHipr " + gain_ + "\" -send \" ganhoHipl " + gain_ + "\" -send \"save "+ pathSave +"\"";
  return obj_exec -> do_command(c);
}

int manipulation_filters::filter_bandpass(string p, string frequency_l_input, string frequency_r_input, string gain_l_input, string gain_r_input, string q_in_left, string q_in_right, string pSave)
{
  char * au_files = getenv("AURIS_FILES");
  if(au_files == NULL)
  {
    clog << "Erro com a variavel AURIS_FILES nao setada, abortando.\n";
    exit(-1);
  }
  char *path = (char *)malloc(100);
  char *pathSave = (char *)malloc(100);
  strcat(path, au_files);
  strcat(path, p.c_str());
  strcat(pathSave, au_files);
  strcat(pathSave, pSave.c_str());
  string frequency_l = (frequency_l_input.c_str() != NULL)? frequency_l_input : "250";
  string frequency_r = (frequency_r_input.c_str() != NULL)? frequency_r_input : "250";
  string q_l	     = (q_in_left.c_str() != NULL)? q_in_left : "0.5";
  string q_r	     = (q_in_right.c_str() != NULL)? q_in_right : "0.5";
  string gain_l     = (gain_l_input.c_str() != NULL)? gain_l_input: "2";
  string gain_r     = (gain_r_input.c_str() != NULL)? gain_r_input: "2";
  command  *obj_exec      = new command();
  string c = "pd  -open \"" + loc_patch +"\" -send \"local "+ path +"\" -send \"pd dsp 1\" -send \"controlBnpl 1\" -send \"controlBnpr 1\" -send \"qbnpl " + q_l + "\" -send \"qbnpr " + q_r + "\" -send \"fbnpr " + frequency_l + "\" -send \"fbnpl " + frequency_r + "\" -send \"ganhoBnpl " + gain_l + "\" -send \"ganhoBnpr " + gain_r + "\" -send \"save "+ pathSave  +"\"" ;
  //cout << c << endl;
  return obj_exec -> do_command(c);
}


int command::do_command(string task)
{
  int ret = -1;
  try{
    ret = system(task.c_str());
  }catch(exception& e){
    clog << "Erro vindo de system. Mensagem: " << e.what() << endl;
  }
  return ret;
}


