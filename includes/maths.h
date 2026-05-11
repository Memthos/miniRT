#ifndef MATHS_H
# define MATHS_H

# include <types.h>

/// @brief Round the passed number with the given precision (status can be NULL)
/// @param nb The number to pass
/// @param precision The wanted precision
/// @param status The status that will be updated in case of error
/// @return The number with the wanted precision
double	ft_round(double nb, t_uint precision, t_status *status);

#endif
