   #include "../includes/ClapTrap.hpp"

   ClapTrap::ClapTrap():name_("Unnamed"),hit_points_(10),energy_points_(10), attack_damage_(0)
   {
        std::cout<<"Default Constructor is called.\n";        

   }

   ClapTrap::ClapTrap(std::string name):hit_points_(10),energy_points_(10), attack_damage_(0){
    std::cout<<"Parameterized Constructor is called.\n";        
    name_=name;
  }
  
  ClapTrap::ClapTrap(const ClapTrap &obj)
  {
    std::cout<<"Copy constructor is called\n";
    *this=obj;
  }

  ClapTrap::~ClapTrap()
  {
    std::cout<<"Destructor is called. ClapTrap "<<name_<<" is destroyed \n";
  }

  ClapTrap& ClapTrap::operator=(const ClapTrap &obj)
  {
    std::cout<<"Copy assignment operator called\n";
    if(this != &obj)
    {
        name_ = obj.name_;
        attack_damage_ = obj.attack_damage_;
        hit_points_ = obj.hit_points_;
        energy_points_ = obj.energy_points_;
    }
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
        std::cout<<"Hit points: "<<hit_points_<<"\n";
        std::cout<<"Energy points: "<<energy_points_<<"\n";
        std::cout<<"Damage points: "<<attack_damage_<<"\n";
    }