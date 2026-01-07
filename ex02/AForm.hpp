#ifndef AFORM_HPP
#define AFORM_HPP

#include <iostream>
#include <string>
#include "Bureaucrat.hpp"
#include <stdexcept>

class Bureaucrat;

class AForm
{
private:
    const std::string _name;
    bool _isSigned;
    const int _gradeToSign;
    const int _gradeToExecute;
public:
    AForm();
    AForm(const std::string& name, int gradeToSign, int gradeToExecute);
    AForm(const AForm& other);
    AForm& operator=(const AForm& other);
    virtual ~AForm();
    std::string getName() const;
    bool getIsSigned() const;
    int getGradeToSign() const;
    int getGradeToExecute() const;
    virtual void execute(const Bureaucrat& executor) const = 0;
    void beSigned(const Bureaucrat& bureaucrat);
    class GradeTooHighException : public std::exception 
    {
        public:
            const char* what() const noexcept override;
    };
    class GradeTooLowException : public std::exception 
    {
        public:
            const char* what() const noexcept override;
    };
};

std::ostream& operator<<(std::ostream& os, const AForm& form);

#endif
