/*****************************************************************************/
/*!
\file solution.h
\author Josiah Goh
\par email: goh.j\@digipen.edu
\par DigiPen login: goh.j
\par Course: CS225
\par Assignment #7
\date 05/08/2020
\brief
This file contains the implementation of the following functions:
print_file_names
print_non_empty_files
print_empty_files
get_parameters
remove_empty
Hours spent on this assignment: 6 hours
Specific portions that gave you the most trouble: Restriction on keyword auto.
*/
/*****************************************************************************/
#ifndef _SOLUTION_H_
#define _SOLUTION_H_

/*****************************************************************************/
/*!
  \brief
    Print the file names of the given file records.
    
  \param map
    The map holding the file records.
*/
/*****************************************************************************/
void print_file_names(const file_records& map)
{
  // invoke print function for each of the element of the map
  for_each(
    std::cbegin(map), 
    std::cend(map), 
    std::bind(
      &print_file_name, 
      std::bind(&split, std::placeholders::_1)
    )
  );
}

/*****************************************************************************/
/*!
  \brief
    Print the file names of the given file records that is not empty.
    
  \param map
    The map holding the file records.
    
  \return number of non-empty files.
*/
/*****************************************************************************/
size_t print_non_empty_files(const file_records& map)
{
  file_records filenames;
  
  // copy if file size of the record is non zero.
  std::copy_if(
    std::cbegin(map),
    std::cend(map),
    std::inserter(filenames, std::end(filenames)),
    std::bind(&check_if_empty, std::placeholders::_1, true)
  );
   
  print_file_names(filenames);
  return std::size(filenames);
}

/*****************************************************************************/
/*!
  \brief
    Print the file names of the given file records that is empty.
    
  \param map
    The map holding the file records.
    
  \return number of empty files.
*/
/*****************************************************************************/
size_t print_empty_files(const file_records& map)
{
  file_records filenames;
  
  // copy if the file size of the record is zero
  std::remove_copy_if(
    std::cbegin(map),
    std::cend(map),
    std::inserter(filenames, std::end(filenames)),
    std::bind(&check_if_empty, std::placeholders::_1, true)
  );
    
  print_file_names(filenames);
  return std::size(filenames);
}

/*****************************************************************************/
/*!
  \brief
    Make a tuple holding the reference to the map.
    
  \param map
    The map holding the file records.
    
  \return the tuple holding the reference to the map.
*/
/*****************************************************************************/
std::tuple<std::reference_wrapper<file_records>> 
get_parameters(file_records& map)
{
  return std::make_tuple(std::ref(map));
}

/*****************************************************************************/
/*!
  \brief
    Remove empty file from the map given.
    
  \param map
    The map holding the file records.
*/
/*****************************************************************************/
void remove_empty(file_records& map)
{
  file_records non_empty_record;
  // copy if file record is not empty
  std::copy_if(
    std::cbegin(map),
    std::cend(map),
    std::inserter(non_empty_record, std::end(non_empty_record)),
    std::bind(&check_if_empty, std::placeholders::_1, true)
  );
  
  map = non_empty_record; 
}
#endif