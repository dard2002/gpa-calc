#include <vector>

class gpa
{
    private:
        std::vector<int> _grades;
        double _credit_hours;

    public:
        // Declare non-primitives in constructor as constant references to prevent unncessary copying of that object
        gpa(const std::vector<int>& grades);

        double get_gpa() const noexcept;
        double get_wam() const noexcept;
        double get_credit_hours() const noexcept;
        double get_gpa_7() const noexcept;
};
