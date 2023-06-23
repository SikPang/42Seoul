<?php

// define( 'DB_NAME', 'WORDPRESS_DB_NAME') );
// define( 'DB_USER', 'WORDPRESS_DB_USER') );
// define( 'DB_PASSWORD', 'WORDPRESS_DB_PASSWORD') );
// define( 'DB_HOST', 'WORDPRESS_DB_HOST') );

// $table_prefix = 'wp_';
// define( 'AUTH_KEY', 'WORDPRESS_AUTH_KEY') );
// define( 'SECURE_AUTH_KEY', 'WORDPRESS_SECURE_AUTH_KEY') );
// define( 'LOGGED_IN_KEY', 'WORDPRESS_LOGGED_IN_KEY') );
// define( 'NONCE_KEY', 'WORDPRESS_NONCE_KEY') );
// define( 'AUTH_SALT', 'WORDPRESS_AUTH_SALT') );
// define( 'SECURE_AUTH_SALT', 'WORDPRESS_SECURE_AUTH_SALT') );
// define( 'LOGGED_IN_SALT', 'WORDPRESS_LOGGED_IN_SALT') );
// define( 'NONCE_SALT', 'WORDPRESS_NONCE_SALT') );

// $table_prefix = 'wp_';
// define( 'AUTH_KEY', 'WORDPRESS_AUTH_KEY') );
// define( 'SECURE_AUTH_KEY', 'WORDPRESS_SECURE_AUTH_KEY') );
// define( 'LOGGED_IN_KEY', 'WORDPRESS_LOGGED_IN_KEY') );
// define( 'NONCE_KEY', 'WORDPRESS_NONCE_KEY') );
// define( 'AUTH_SALT', 'WORDPRESS_AUTH_SALT') );
// define( 'SECURE_AUTH_SALT', 'WORDPRESS_SECURE_AUTH_SALT') );
// define( 'LOGGED_IN_SALT', 'WORDPRESS_LOGGED_IN_SALT') );
// define( 'NONCE_SALT', 'WORDPRESS_NONCE_SALT') );

define( 'DB_NAME', 'mydb' );
define( 'DB_USER', 'kwsong' );
define( 'DB_PASSWORD', '1234' );
define( 'DB_HOST', 'mariadb' );

$table_prefix = 'wp_';

define( 'WP_DEBUG', false );

if ( ! defined( 'ABSPATH' ) ) {
    define( 'ABSPATH', dirname( __FILE__ ) . '/' );
}

require_once ABSPATH . 'wp-settings.php';

