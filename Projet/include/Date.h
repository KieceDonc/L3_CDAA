/* inspired and modified from http://www.cplusplus.com/forum/beginner/158359/ */

class Date{
  
  private:
	  int month, day, year;

    void setDay(const int day);
    void setMonth(const int month);
    void setYear(const int year);

  public:
	  Date();
	  Date(const int month,const int day,const int year);

    ~Date(){}

    std::string getDebugValues();

};