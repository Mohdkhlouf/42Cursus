   #include "ClapTrap.hpp"

   ClapTrap::ClapTrap():name_("Unnamed"),hit_points_(10),energy_points_(10), attack_damage_(0)
   {
        std::cout<<"ClapTrap Default Constructor is called.\n";        

   }

   ClapTrap::ClapTrap(const std::string &name):hit_points_(10),energy_points_(10), attack_damage_(0){
    std::cout<<"ClapTrap Parameterized Constructor is called.\n";        
    name_=name;
  }
  ClapTrap::ClapTrap(const ClapTrap &obj)
  {
    std::cout<<"ClapTrap Copy constructor is called\n";
    *this=obj;
  }

  ClapTrap::~ClapTrap()
  {
    std::cout<<"ClapTrap Destructor is called. ClapTrap "<<name_<<" is destroyed \n";
  }

  ClapTrap& ClapTrap::operator=(const ClapTrap &obj)
  {
    std::cout<<"ClapTrap Copy assignment operator called\n";
    if(this == &obj)
    {
        return(*this);
    }
    *this = obj;
    return(*this);
  }

void ClapTrap::attack(const std::string& target)
{
    if(energy_points_ == 0)
        std::cout<<"ClapTrap "<<name_<<" cannot attack because it has no Energy points left.\n";
    else if(hit_points_ == 0)
        std::cout<<"ClapTrap "<<name_<<" cannot attack because it has no Hit points left.\n";
    else
    {
        std::cout<<"ClapTrap "<<name_<<" attacks "<<target
                 <<" causing "<<this->attack_damage_<<" points of damage!\n";
        energy_points_--;
    }
}
void ClapTrap::takeDamage(unsigned int amount)
{
    if(hit_points_ == 0)
        std::cout<<"ClapTrap "<<name_<<" is already dead!.\n";
    else if(amount >= hit_points_)
    {
        std::cout<<"ClapTrap "<<name_<<" is dead now! after "<<amount<<" attack points!\n";
        hit_points_ = 0;
    }
    else
    {
        std::cout<<"ClapTrap "<<name_<<" is under attack and lost "<< amount <<" hit points.\n";
        hit_points_=hit_points_ - amount;
    }
}
void ClapTrap::beRepaired(unsigned int amount){
    if(energy_points_ == 0)
        std::cout<<"ClapTrap "<<name_<<" cannot be repaired because no enough energy points left.\n";
    else if(hit_points_ == 0)
        {
        std::cout<<"ClapTrap "<<name_<<" is dead already.\n";
        }
    else
        {
        std::cout<<"ClapTrap "<<name_<<" is repaired by "<<amount<<" energy points.\n";
        energy_points_--;
        hit_points_ = hit_points_ + amount;
        }
    }

// Getters
    int ClapTrap::getHitPoints()
    {
        return (hit_points_);
    }
    int ClapTrap::getEnergyPoints()
    {
        return (energy_points_);
    }
    int ClapTrap::getAttackDamage()
    {
        return(attack_damage_);
    }

// printing
    void ClapTrap::print()
    {
        std::cout<<"Hit poinsts: "<<this->hit_points_<<"\n";
        std::cout<<"Energy poinsts: "<<this->energy_points_<<"\n";
        std::cout<<"Damage poinsts: "<<this->attack_damage_<<"\n";
    }