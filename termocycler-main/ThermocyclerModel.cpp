#ifndef THERMOCYCLER_MODEL_H
#define THERMOCYCLER_MODEL_H

class ThermocyclerModel {
  private: 
    int count;

  public:
    int getCount() {
      return this->count;  
    }

    void setCount(int count) {
      this->count = count;
    }
};

#endif
