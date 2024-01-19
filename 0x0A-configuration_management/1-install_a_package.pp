#!/usr/bin/puppet
# Install Flask version 2.1.0 using pip3
package { 'flask':
  ensure   => '2.1.0',  # Ensures the latest version is installed
  provider => 'pip3',
}
package { 'werkzeug':
  ensure   => '2.1.1',  # Ensures the latest version is installed
  provider => 'pip3',
}
