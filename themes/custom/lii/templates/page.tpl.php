<div id="page" class="<?php print $classes; ?>"<?php print $attributes; ?>>
    <header class="navbar navbar-inverse navbar-fixed-top navbar-white" role="banner">
        <div class="container">
            <div class="navbar-header">
                <a class="navbar-brand" href="<?php print $front_page; ?>"><img src="<?php print $logo; ?>" alt="<?php print t('Home'); ?>"/></a>
            </div>
            <div class="collapse navbar-collapse">
                <?php if ($page['navbar']): ?>
                    <?php print render($page['navbar']); ?>
                <?php endif; ?>
            </div>
        </div>
    </header><!--/header-->

    <section id="services" class="dark-green-background">
        <div class="container">
            <div class="row">
                <div class="col-sm-12 col-md-12">
                    <div class="media">
                        <?php if (file_exists(drupal_get_path('theme', 'lii') .'/images/country-flags/'. lii_get_country_code_from_name($title) .'.png')): ?>
                            <div class="pull-left"> <!-- this is causing problems. if taken out, problem solved -->
                                <img class="flag-md" src="<?php print '/'. drupal_get_path('theme', 'lii') .'/images/country-flags/'. lii_get_country_code_from_name($title) .'.png'; ?>" alt="<?php print $title; ?>" width="40">
                            </div>
                        <?php endif; ?>

                        <?php if ($title): ?>
                            <div class="media-body">
                                <h3 class="media-heading white-heading"><?php print $title; ?></h3>
                            </div>
                        <?php endif; ?>

                        <div class="search-bar">
                            <?php print render($page['search_section']); ?>
                        </div>
                    </div>
                </div>
            </div><!--/.row-->
        </div>
    </section><!--/#services-->

    <section id="services">
        <div class="container">
            <div class="row">
                <div class="col-sm-6 col-md-8 extra-padding-right">
                    <div id="content-area">
                        <?php if ($tabs): ?>
                              <div class="tabs"><?php print render($tabs); ?></div>
                        <?php endif; ?>

                        <?php print $messages; ?>
                        <?php print render($page['content']) ?>
                    </div>
                </div>
                <div class="col-sm-6 col-md-4">
                    <?php print render($page['sidebar_second']); ?>
                </div>
            </div><!--/.row-->
        </div>
    </section><!--/#services-->

    <section id="recent-works" class="white-background">
        <div class="container">
            <div class="row">
                <div class="col-sm-12">
                    <h3 class="media-heading dark-grey-heading">Developed by:</h3>
                </div>
            </div>
            <div class="row">
                <div class="col-md-4 col-sm-6 logo-margin-bottom">
                    <img src="<?php print base_path() . path_to_theme(); ?>/images/developed-by/african-lii-logo.png" alt="African Lii" width="200">
                </div><!--/.col-md-4-->

                <div class="col-md-4 col-sm-6 logo-margin-bottom">
                    <img src="<?php print base_path() . path_to_theme(); ?>/images/developed-by/saflii-logo.png" alt="African Lii" width="200">
                </div><!--/.col-md-4-->

                <div class="col-md-4 col-sm-6 logo-margin-bottom">
                    <img src="<?php print base_path() . path_to_theme(); ?>/images/developed-by/dgru-logo.png" alt="African Lii" width="200">
                </div><!--/.col-md-4-->

            </div><!--/.row-->
        </div>
    </section><!--/#recent-works-->

    <section id="bottom" class="dark-green-background">
        <div class="container">
            <div class="row">
                <div class="col-sm-12">
                    <?php print render($page['footer_blocks']); ?>
                </div>
            </div>
        </div>
    </section><!--/#bottom-->

    <footer id="footer" class="grey-green-background">
        <div class="container">
            <div class="row">
                <div class="col-sm-6">
                    &copy; 2016 Pocket Law.
                </div>

                <?php if ($page['footer']): ?>
                  <footer id="footer">
                    <?php print render($page['footer']); ?>
                  </footer> <!-- /footer -->
                <?php endif; ?>
            </div>
        </div>
    </footer><!--/#footer-->
</div>