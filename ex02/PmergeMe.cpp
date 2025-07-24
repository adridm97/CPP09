/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrian <adrian@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 17:35:00 by adrian            #+#    #+#             */
/*   Updated: 2025/07/23 17:03:42 by adrian           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMe::PmergeMe() {}

PmergeMe::PmergeMe(const PmergeMe &other) : vectorData(other.vectorData), vectorSorted(other.vectorSorted), dequeData(other.dequeData), dequeSorted(other.dequeSorted) {}

PmergeMe &PmergeMe::operator=(const PmergeMe &other)
{
    if (this != &other)
    {
        vectorData = other.vectorData;
        vectorSorted = other.vectorSorted;
        dequeData = other.dequeData;
        dequeSorted = other.dequeSorted;
    }
    return *this;
}

PmergeMe::~PmergeMe() {}

//Secuencia Jacobsthal: J(n) = J(n-1) + 2*J(n-2) para n >= 2
size_t PmergeMe::jacobsthal(size_t n) const
{
    if (n == 0) return 0;
    if (n == 1) return 1;
    size_t a = 0, b = 1, c = 0;
    for (size_t i = 2; i <= n; ++i)
    {
        c = b + 2 * a;
        a = b;
        b = c;
    }
    return c;
}

//Toma de tiempo
double PmergeMe::getCurrentTime() const
{
    struct timeval tv;
    //Obtiene el tiempo actual del sistema en microsegundos
    gettimeofday(&tv, NULL);
    
    return (tv.tv_sec * 1000000.0 + tv.tv_usec);
}

//Cargar datos
void PmergeMe::loadData(int argc, char **argv)
{
    vectorData.clear();
    dequeData.clear();
    for (int i = 1; i < argc; ++i)
    {
        char *end;
        long num = std::strtol(argv[i], &end, 10);
        if (*end != '\0' || num <= 0 || num > INT_MAX)
        {
            std::cerr << "Error" << std::endl;
            std::exit(1);
        }
        vectorData.push_back((int)num);
        dequeData.push_back((int)num);
    }
}

//Imprimir antes
void PmergeMe::printBefore() const
{
    std::cout << "Before: ";
    for (size_t i = 0; i < vectorData.size(); ++i)
        std::cout << vectorData[i] << " ";
    std::cout << std::endl;
}

//Imprimir después
void PmergeMe::printAfter() const
{
    std::cout << "After: ";
    for (size_t i = 0; i < vectorSorted.size(); ++i)
        std::cout << vectorSorted[i] << " ";
    std::cout << std::endl;
}

//Imprimir tiempos
void PmergeMe::printTimes(double vTime, double dTime) const
{
    std::cout << "Time to process a range of " << vectorSorted.size()
              << " elements with std::vector : " << vTime << " us" << std::endl;
    std::cout << "Time to process a range of " << dequeSorted.size()
              << " elements with std::deque : " << dTime << " us" << std::endl;
}

//getter del vector
const std::vector<int>& PmergeMe::getVectorSorted() const
{
    return vectorSorted;
}

//getter del deque
const std::deque<int>& PmergeMe::getDequeSorted() const
{
    return dequeSorted;
}

// Ford-Jhonson
void PmergeMe::fordJohnsonSortVector(std::vector<int> &v)
{
    size_t n = v.size();
    if (n <= 1)
        return;
    //Emparejar los elementos de dos en dos
    std::vector< std::pair<int, int> > pairs;
    int last = -1;
    if (n % 2 != 0)
    {
        last = v.back();
        v.pop_back();
        --n;
    }
    //Inserta en el vector de pares en orden pequeño-grande
    size_t i;
    for (i = 0; i < n; i += 2)
    {
        int a = v[i], b = v[i+1];
        if (a < b)
            pairs.push_back(std::pair<int,int>(a, b));
        else
            pairs.push_back(std::pair<int,int>(b, a));
    }
    //Crear la "main chain" (mayores de cada pareja)
    std::vector<int> mainChain;
    for (i = 0; i < pairs.size(); ++i)
        mainChain.push_back(pairs[i].second);
    //Ordenar recursivamente la "main chain"
    if (!mainChain.empty())
        fordJohnsonSortVector(mainChain);
    //Crear el array de "pendientes" (menores de cada pareja)
    std::vector<int> pendings;
    for (i = 0; i < pairs.size(); ++i)
        pendings.push_back(pairs[i].first);
    //Calcular las posiciones de inserción usando Jacobsthal
    std::vector<size_t> jacobIndices;
    size_t k;
    for (k = 1; ; ++k)
    {
        size_t j = jacobsthal(k);
        if (j == 0 || j - 1 >= pendings.size())
            break;
        jacobIndices.push_back(j - 1);
    }
    std::vector<bool> inserted(pendings.size(), false);
    //Insertar los pendientes en las posiciones de Jacobsthal
    for (i = 0; i < jacobIndices.size(); ++i)
    {
        size_t pendIdx = jacobIndices[i];
        if (pendIdx < pendings.size() && !inserted[pendIdx])
        {
            int val = pendings[pendIdx];
            std::vector<int>::iterator pos = std::lower_bound(mainChain.begin(), mainChain.end(), val);
            mainChain.insert(pos, val);
            inserted[pendIdx] = true;
        }
    }
    //Insertar el resto de pendientes
    for (i = 0; i < pendings.size(); ++i)
    {
        if (!inserted[i])
        {
            int val = pendings[i];
            std::vector<int>::iterator pos = std::lower_bound(mainChain.begin(), mainChain.end(), val);
            mainChain.insert(pos, val);
        }
    }
    //Si había elemento impar, se inserta al final
    if (last != -1)
    {
        std::vector<int>::iterator pos = std::lower_bound(mainChain.begin(), mainChain.end(), last);
        mainChain.insert(pos, last);
    }
    v = mainChain;
}
//Lo mismo que en vector pero con deque
void PmergeMe::fordJohnsonSortDeque(std::deque<int> &d)
{
    size_t n = d.size();
    if (n <= 1)
        return;

    std::deque< std::pair<int, int> > pairs;
    int last = -1;
    if (n % 2 != 0)
    {
        last = d.back();
        d.pop_back();
        --n;
    }
    size_t i;
    for (i = 0; i < n; i += 2)
    {
        int a = d[i], b = d[i+1];
        if (a < b)
            pairs.push_back(std::pair<int,int>(a, b));
        else
            pairs.push_back(std::pair<int,int>(b, a));
    }

    std::deque<int> mainChain;
    for (i = 0; i < pairs.size(); ++i)
        mainChain.push_back(pairs[i].second);

    if (!mainChain.empty())
        fordJohnsonSortDeque(mainChain);

    std::deque<int> pendings;
    for (i = 0; i < pairs.size(); ++i)
        pendings.push_back(pairs[i].first);

    std::vector<size_t> jacobIndices;
    size_t k;
    for (k = 1; ; ++k)
    {
        size_t j = jacobsthal(k);
        if (j == 0 || j - 1 >= pendings.size())
            break;
        jacobIndices.push_back(j - 1);
    }
    std::vector<bool> inserted(pendings.size(), false);

    for (i = 0; i < jacobIndices.size(); ++i)
    {
        size_t pendIdx = jacobIndices[i];
        if (pendIdx < pendings.size() && !inserted[pendIdx])
        {
            int val = pendings[pendIdx];
            std::deque<int>::iterator pos = std::lower_bound(mainChain.begin(), mainChain.end(), val);
            mainChain.insert(pos, val);
            inserted[pendIdx] = true;
        }
    }
    for (i = 0; i < pendings.size(); ++i)
    {
        if (!inserted[i])
        {
            int val = pendings[i];
            std::deque<int>::iterator pos = std::lower_bound(mainChain.begin(), mainChain.end(), val);
            mainChain.insert(pos, val);
        }
    }
    if (last != -1)
    {
        std::deque<int>::iterator pos = std::lower_bound(mainChain.begin(), mainChain.end(), last);
        mainChain.insert(pos, last);
    }
    d = mainChain;
}

//Sort y resultado final
void PmergeMe::sortVector()
{
    vectorSorted = vectorData;
    fordJohnsonSortVector(vectorSorted);
}

void PmergeMe::sortDeque()
{
    dequeSorted = dequeData;
    fordJohnsonSortDeque(dequeSorted);
}
