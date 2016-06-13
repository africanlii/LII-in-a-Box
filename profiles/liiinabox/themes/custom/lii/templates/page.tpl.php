<div id="page" class="<?php print $classes; ?>"<?php print $attributes; ?>>
    <header class="navbar navbar-inverse navbar-fixed-top navbar-white" role="banner">
        <div class="container">
            <div class="navbar-header">
                <a class="navbar-brand" href="<?php print $front_page; ?>"><img src="<?php print $logo; ?>" alt="<?php print t('Home'); ?>"/></a>
            </div>
            <div class="collapse navbar-collapse">
                <?php if ($main_menu || $secondary_menu || $page['navbar']): ?>
                    <?php print theme('links', array('links' => $main_menu, 'attributes' => array('id' => 'primary', 'class' => array('nav', 'navbar-nav', 'navbar-right')))); ?>
                <?php endif; ?>
            </div>
        </div>
    </header><!--/header-->

    <section id="services" class="dark-green-background">
        <div class="container">
            <div class="row">
                <div class="col-sm-12 col-md-12 extra-padding-right">
                    <div id="content-header" class="header_thing">
                        <div class="title-bar">
                            <?php if ($title): ?>
                              <h3 class="media-heading white-heading"><?php print $title; ?></h3>
                            <?php endif; ?>
                        </div>

                        <div class="search-bar">
                            <?php print render($page['search_section']); ?>
                        </div>
                    </div> <!-- /#content-header -->
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
                    <?php print render($page['sidebar_right']); ?>
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
            </div>
        </div>
    </footer><!--/#footer-->
</div>