#ifndef INFOR_EACH_COUNTRY_H
#define INFOR_EACH_COUNTRY_H
#include <QTextStream>

class infor_each_country
{
public:
    infor_each_country();
    void setCountry(QString x){Country=x;}
    QString getCountry(){return Country;}

    void setCountryCode(QString x){CountryCode=x;}
    QString getCountryCode(){return CountryCode;}

    void setSlug(QString x){Slug=x;}
    QString getSlug(){return Slug;}

    void setNewConfirmed(int x){NewConfirmed=x;}
    int getNewConfirmed(){return NewConfirmed;}

    void setTotalConfirmed(int x){TotalConfirmed=x;}
    int getTotalConfirmed(){return TotalConfirmed;}

    void setNewDeaths(int x){NewDeaths=x;}
    int getNewDeaths(){return NewDeaths;}

    void setTotalDeaths(int x){TotalDeaths=x;}
    int getTotalDeaths(){return TotalDeaths;}

    void setNewRecovered(int x){NewRecovered=x;}
    int getNewRecovered(){return NewRecovered;}

    void setTotalRecovered(int x){TotalRecovered=x;}
    int getTotalRecovered(){return TotalRecovered;}

    void setDate(QString x){Date=x;}
    QString getDate(){return Date;}

private:
    QString Country;
    QString CountryCode;
    QString Slug;
    int NewConfirmed;
    int TotalConfirmed;
    int NewDeaths;
    int TotalDeaths;
    int NewRecovered;
    int TotalRecovered;
    QString Date;

};

#endif // INFOR_EACH_COUNTRY_H
